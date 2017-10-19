#include <windows.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <Shlobj.h>
#include <string>
#include <iostream>
#include "Filter.h"
using namespace std;

void startHook();
void startCheck();
void startFS();
void startWR();
void updatedata(string datapath, string rowspath);
void turnon();
void turnoff();
void webturnon(string website);
void webturnoff(string website);
BOOL CALLBACK FindTaskbars(HWND hwnd, LPARAM lParam);

int hp[1000], mp[1000], he[1000], me[1000], day[1000], fq[1000], to[1000];
string website[1000];
bool websiteon[1000];
string rows[1000];
vector<int> del;
vector<string> taskbars;
STARTUPINFO si, si2, si3;
PROCESS_INFORMATION pi, pi2, pi3;
SHELLEXECUTEINFO shExInfo = {0};
DWORD ec;
fstream f, r;
bool on, turnedon, warning;
int files=0;
time_t now; struct tm ct;
string hostsfile;
PacketFilter pf;

int main()
{
    string hp1, mp1, he1, me1, day1, fq1, to1;
    bool uvjet;
    MSG msg;

    RegisterHotKey(NULL, 1, MOD_CONTROL, VK_F12);

    char wd[1000];
    GetWindowsDirectoryA(wd, sizeof(wd));
    hostsfile = string(wd) + "\\System32\\drivers\\etc\\hosts";

    char lad[1000];
    SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, lad);
    string usagedatapath(lad), usagerowspath(lad);
    usagedatapath.append("\\Licoforen\\Usagedata.dat");
    usagerowspath.append("\\Licoforen\\Usagerows.dat");
    string webdatapath(lad), webrowspath(lad);
    webdatapath.append("\\Licoforen\\Webdata.dat");
    webrowspath.append("\\Licoforen\\Webrows.dat");

    EnumChildWindows(GetDesktopWindow(), FindTaskbars, NULL);

    pf.StartFirewall();

    while(true)
    {
        GetExitCodeProcess(shExInfo.hProcess, &ec);

        //Usage
        //---------------------------------------------------------------------------------------------------------------

        f.open(usagedatapath.c_str());
        if(f.is_open() && ec!=259)
        {
            r.open(usagerowspath.c_str());
            files=0;
            for(int i=0; f >> hp1 >> mp1 >> he1 >> me1 >> day1 >> fq1 >> to1; i++)
            {
                istringstream(hp1) >> hp[i];
                istringstream(mp1) >> mp[i];
                istringstream(he1) >> he[i];
                istringstream(me1) >> me[i];
                istringstream(day1) >> day[i];
                istringstream(fq1) >> fq[i];
                istringstream(to1) >> to[i];
                files++;
                getline(r, rows[i]);
            }
            r.close();
            f.close();

            on = false;
            for(int i=0; i<files; i++)
            {
                now = time(0);
                ct = *localtime(&now);

                if(((1<<ct.tm_wday) & day[i]) > 0)
                {
                    if(hp[i]<he[i] || (hp[i]==he[i] && mp[i]<me[i]))
                        uvjet = (ct.tm_hour>=hp[i] && (ct.tm_min>=mp[i] || ct.tm_hour>hp[i])) && (ct.tm_hour<=he[i] && (ct.tm_min<me[i] || ct.tm_hour<he[i]));
                    else
                        uvjet = (ct.tm_hour>=hp[i] && (ct.tm_min>=mp[i] || ct.tm_hour>hp[i])) || (ct.tm_hour<=he[i] && (ct.tm_min<me[i] || ct.tm_hour<he[i]));

                    if(uvjet)
                    {
                        on = true;
                        to[i] = 1;
                        updatedata(usagedatapath, usagerowspath);
                    }
                    else if(to[i] == 1)
                    {
                        if(fq[i]==0 && day[i]-(1<<ct.tm_wday)==0)
                            del.push_back(i);
                        else if(fq[i]==0)
                        {
                            day[i]-=(1<<ct.tm_wday);
                            updatedata(usagedatapath, usagerowspath);
                        }
                    }

                    if(mp[i]==0)
                    {
                        if(ct.tm_hour==hp[i]-1 && ct.tm_min==59 && !warning)
                            startWR();
                    }
                    else
                        if(ct.tm_hour==hp[i] && ct.tm_min==mp[i]-1 && !warning)
                            startWR();
                }
            }

            if(on && !turnedon)
                turnon();
            else if(!on && turnedon)
                turnoff();

            if(!del.empty())
            {
                updatedata(usagedatapath, usagerowspath);
                files-=del.size();
            }
        }

        //-------------------------------------------------------------------------------------------------------------------
        //Web
        //-------------------------------------------------------------------------------------------------------------------

        f.open(webdatapath.c_str());
        if(f.is_open() && ec!=259)
        {
            r.open(webrowspath.c_str());
            files=0;
            for(int i=0; f >> website[i] >> hp1 >> mp1 >> he1 >> me1 >> day1; i++)
            {
                istringstream(hp1) >> hp[i];
                istringstream(mp1) >> mp[i];
                istringstream(he1) >> he[i];
                istringstream(me1) >> me[i];
                istringstream(day1) >> day[i];
                files++;
            }
            r.close();
            f.close();

            for(int i=0; i<files; i++)
            {
                now = time(0);
                ct = *localtime(&now);

                if(((1<<ct.tm_wday) & day[i]) > 0)
                {
                    if(hp[i]<he[i] || (hp[i]==he[i] && mp[i]<me[i]))
                        uvjet = ((ct.tm_hour>=hp[i] && (ct.tm_min>=mp[i] || ct.tm_hour>hp[i])) && (ct.tm_hour<=he[i] && (ct.tm_min<me[i] || ct.tm_hour<he[i]))) || hp[i]==-1;
                    else
                        uvjet = ((ct.tm_hour>=hp[i] && (ct.tm_min>=mp[i] || ct.tm_hour>hp[i])) || (ct.tm_hour<=he[i] && (ct.tm_min<me[i] || ct.tm_hour<he[i]))) || hp[i]==-1;

                    if(uvjet && !websiteon[i])
                    {
                        webturnon(website[i]);
                        websiteon[i] = true;
                    }
                    else if(!uvjet && websiteon[i])
                    {
                        webturnoff(website[i]);
                        websiteon[i] = false;
                    }
                }
            }
        }

        //-------------------------------------------------------------------------------------------------------------------

        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            if(msg.message == WM_HOTKEY)
                startCheck();

        Sleep(500);
    }

    pf.StopFirewall();
    return 0;
}

//Usage
//----------------------------------------------------------------------------------------------------------------------------

void turnon()
{
    turnedon = true;
    startHook();
    startFS();
    SendMessage(GetForegroundWindow(), 793, 0x200EB0, 9 * 0x10000);
    SendMessage(GetForegroundWindow(), 793, 0x200EB0, 10 * 0x10000);
    SendMessage(GetForegroundWindow(), 793, 0x200EB0, 8 * 0x10000);
    for(int i=0;i<taskbars.size();i++)
        ShowWindow(FindWindowA(taskbars[i].c_str(), ""), SW_HIDE);
}

void turnoff()
{
    turnedon = false;
    warning = false;
    for(int i=0;i<taskbars.size();i++)
        ShowWindow(FindWindowA(taskbars[i].c_str(), ""), SW_SHOW);
    SendMessage(GetForegroundWindow(), 793, 0x200EB0, 8 * 0x10000);
    TerminateProcess(pi.hProcess, 0);
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    TerminateProcess(pi3.hProcess, 0);
    CloseHandle( pi3.hProcess );
    CloseHandle( pi3.hThread );
}

void updatedata(string datapath, string rowspath)
{
    f.open(datapath.c_str(), ios_base::out | ios_base::trunc);
    r.open(rowspath.c_str(), ios_base::out | ios_base::trunc);
    for(int i=0; i<files; i++)
    {
        if(del.size()>0 && del[0]==i)
        {
            del.erase(del.begin());
            continue;
        }
        r << rows[i] << endl;
        f << hp[i] << ' ' << mp[i] << ' ' << he[i] << ' ' << me[i] << ' ' << day[i] << ' ' << fq[i] << ' ' << to[i] << endl;
    }
    r.close();
    f.close();
}

void startHook()
{
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    CreateProcess("rh.exe",   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFO structure
        &pi);
}

void startFS()
{
    ZeroMemory( &si3, sizeof(si3) );
    si3.cb = sizeof(si3);
    ZeroMemory( &pi3, sizeof(pi3) );

    CreateProcess("fs.exe",   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si3,            // Pointer to STARTUPINFO structure
        &pi3);           // Pointer to PROCESS_INFORMATION structure
}

void startWR()
{
    warning = true;

    ZeroMemory( &si2, sizeof(si2) );
    si2.cb = sizeof(si2);
    ZeroMemory( &pi2, sizeof(pi2) );

    CreateProcess("wr.exe",   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si2,            // Pointer to STARTUPINFO structure
        &pi2);           // Pointer to PROCESS_INFORMATION structure

    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);
}

void startCheck()
{
    GetExitCodeProcess(shExInfo.hProcess, &ec);
    if(ec!=259)
    {
        shExInfo.cbSize = sizeof(shExInfo);
        shExInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        shExInfo.hwnd = 0;
        shExInfo.lpVerb = "runas";                // Operation to perform
        shExInfo.lpFile = "editor.exe";       // Application to start
        shExInfo.lpParameters = "";                  // Additional parameters
        shExInfo.lpDirectory = 0;
        shExInfo.nShow = SW_SHOW;
        shExInfo.hInstApp = 0;

        ShellExecuteEx(&shExInfo);

        if(turnedon)
            for(int i=0;i<taskbars.size();i++)
                ShowWindow(FindWindowA(taskbars[i].c_str(), ""), SW_HIDE);
    }
}


//----------------------------------------------------------------------------------------------------------------------------
//Web
//----------------------------------------------------------------------------------------------------------------------------

void webturnon(string website)
{
    pf.AddToBlockList(website.c_str());
    pf.AddRemoveFilter(true);
}

void webturnoff(string website)
{
    pf.RemoveFromBlockList(website.c_str());
    pf.AddRemoveFilter(true);
}

//----------------------------------------------------------------------------------------------------------------------------

BOOL CALLBACK FindTaskbars(HWND hwnd, LPARAM lParam)
{
    char title[100];
    GetClassNameA(hwnd, title, sizeof(title));

    string stitle(title);
    if(stitle.find("TrayWnd")!=string::npos)
        taskbars.push_back(stitle);

    return true;
}
