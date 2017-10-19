#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;

int argument(string arg);

int main(int argc, char *argv[])
{
    HKEY hKey;
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL),0);

    DWORD taskmgr = 0x00000000;
    DWORD ctrlpnl = 0x00000000;
    DWORD registry = 0x00000000;
    DWORD cmd = 0x00000000;

    for(int i=1; i<argc; i++)
    {
        switch(argument(argv[i]))
        {
        case 0:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
            taskmgr = 1;
            RegSetValueEx(hKey, "DisableTaskMgr", 0, REG_DWORD, (const BYTE*) &taskmgr, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 1:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
            taskmgr = 0;
            RegSetValueEx(hKey, "DisableTaskMgr", 0, REG_DWORD, (const BYTE*) &taskmgr, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 2:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", &hKey);
            ctrlpnl = 1;
            RegSetValueEx(hKey, "NoControlPanel", 0, REG_DWORD, (const BYTE*) &ctrlpnl, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 3:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", &hKey);
            ctrlpnl = 0;
            RegSetValueEx(hKey, "NoControlPanel", 0, REG_DWORD, (const BYTE*) &ctrlpnl, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 4:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
            registry = 2;
            RegSetValueEx(hKey, "DisableRegistryTools", 0, REG_DWORD, (const BYTE*) &registry, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 5:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
            registry = 0;
            RegSetValueEx(hKey, "DisableRegistryTools", 0, REG_DWORD, (const BYTE*) &registry, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 6:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Policies\\Microsoft\\Windows\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Policies\\Microsoft\\Windows\\System", &hKey);
            cmd = 1;
            RegSetValueEx(hKey, "DisableCMD", 0, REG_DWORD, (const BYTE*) &cmd, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        case 7:
            if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Policies\\Microsoft\\Windows\\System", &hKey)!=ERROR_SUCCESS)
                RegCreateKey(HKEY_CURRENT_USER, "Software\\Policies\\Microsoft\\Windows\\System", &hKey);
            cmd = 0;
            RegSetValueEx(hKey, "DisableCMD", 0, REG_DWORD, (const BYTE*) &cmd, sizeof(DWORD));
            RegCloseKey(hKey);
            break;
        }
    }
    return 0;
}

int argument(string arg)
{
    if(arg=="dtm") return 0;
    else if(arg=="etm") return 1;
    else if(arg=="dcp") return 2;
    else if(arg=="ecp") return 3;
    else if(arg=="drg") return 4;
    else if(arg=="erg") return 5;
    else if(arg=="dcmd") return 6;
    else if(arg=="ecmd") return 7;
    return -1;
}
