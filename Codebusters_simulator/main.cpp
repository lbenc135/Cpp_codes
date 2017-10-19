#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
using namespace std;

#define MAXX 16000
#define MAXY 9000
#define VISIBILITY 2200
#define SPEED 800
#define SPEEDG 400
#define RANGE 1760

HANDLE g_hChildStd_IN_Rd[2];
HANDLE g_hChildStd_IN_Wr[2];
HANDLE g_hChildStd_OUT_Rd[2];
HANDLE g_hChildStd_OUT_Wr[2];

CHAR* AINAME[]={"ai1", "ai2"};

int ghoststamina[]={3, 15, 40};

struct ghost {
    int x, y;
    int value=0, state;
} ghosts[28];

struct buster {
    int x, y;
    int state=0, value=-1;
} busters[10];

void initBusters(int bpp, int my)
{
    switch(bpp)
    {
    case 2:
        busters[0+my*bpp].x = 2024; busters[0+my*bpp].y = 1176;
        busters[1+my*bpp].x = 1176; busters[1+my*bpp].y = 2024;
        break;
    case 3:
        busters[0+my*bpp].x = 1600; busters[0+my*bpp].y = 1600;
        busters[1+my*bpp].x = 2449; busters[1+my*bpp].y = 751;
        busters[2+my*bpp].x = 751; busters[2+my*bpp].y = 2449;
        break;
    case 4:
        busters[0+my*bpp].x = 327; busters[0+my*bpp].y = 2873;
        busters[1+my*bpp].x = 1176; busters[1+my*bpp].y = 2024;
        busters[2+my*bpp].x = 2024; busters[2+my*bpp].y = 1176;
        busters[3+my*bpp].x = 2873; busters[3+my*bpp].y = 327;
        break;
    }

    for(int i=0;i<bpp;i++)
    {
        busters[i+(1-my)*bpp].x = MAXX-busters[i+my*bpp].x;
        busters[i+(1-my)*bpp].y = MAXY-busters[i+my*bpp].y;
    }
}

void createChilds()
{
    for(int i=0;i<2;i++)
    {
        SECURITY_ATTRIBUTES saAttr;
        saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
        saAttr.bInheritHandle = TRUE;
        saAttr.lpSecurityDescriptor = NULL;

        CreatePipe(&g_hChildStd_OUT_Rd[i], &g_hChildStd_OUT_Wr[i], &saAttr, 0);
        SetHandleInformation(g_hChildStd_OUT_Rd[i], HANDLE_FLAG_INHERIT, 0);
        CreatePipe(&g_hChildStd_IN_Rd[i], &g_hChildStd_IN_Wr[i], &saAttr, 0);
        SetHandleInformation(g_hChildStd_IN_Wr[i], HANDLE_FLAG_INHERIT, 0);

        PROCESS_INFORMATION piProcInfo;
        STARTUPINFO siStartInfo;

        ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
        ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
        siStartInfo.cb = sizeof(STARTUPINFO);
        siStartInfo.hStdError = g_hChildStd_OUT_Wr[i];
        siStartInfo.hStdOutput = g_hChildStd_OUT_Wr[i];
        siStartInfo.hStdInput = g_hChildStd_IN_Rd[i];
        siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

        CreateProcess(NULL,AINAME[i],NULL,NULL,TRUE,0,NULL,NULL,&siStartInfo,&piProcInfo);
    }
}

void WriteToChild(string str, int i)
{
    WriteFile(g_hChildStd_IN_Wr[i], str.c_str(), str.length(), NULL, NULL);

    FlushFileBuffers(g_hChildStd_IN_Wr[i]);
}

string ReadFromPipe(void)
{
    CHAR chBuf[256];
    bool success = ReadFile(g_hChildStd_OUT_Rd, chBuf, 256, NULL, NULL);
    return string(chBuf);
}



int main()
{
    srand(time(0));

    int bustersPerPlayer = rand()%3+2;
    int ghostCount = rand()%21+8;
    int myTeamId = rand()%2;

    // initialize ghosts
    for(int i=0;i<ghostCount;i++)
    {
        int x=0, y=0;
        while(x<3000 && y<3000 || x>MAXX-3000 && y>MAXY-3000)
        {
            x = rand()%MAXX;
            y = rand()%MAXY;
        }
        ghosts[i].x=x; ghosts[i].y=y;
        ghosts[i].state = ghoststamina[rand()%3];
    }

    // initialize busters
    initBusters(bustersPerPlayer, myTeamId);

    int turn=400;
    while(turn--)
    {

    }
}
