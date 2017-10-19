#include <windows.h>
using namespace std;

HMODULE hKBHookDLL;

typedef void (*LPSetKBHook)(void);
LPSetKBHook SetKBHook = NULL;

typedef void (*LPKillKBHook)(void);
LPKillKBHook KillKBHook = NULL;

BOOL LoadHookDLL()
{
    hKBHookDLL = LoadLibrary("hooks.dll");
    if (!hKBHookDLL) return(0);

    SetKBHook = (LPSetKBHook)GetProcAddress(hKBHookDLL, "SetKBHook");
    if (!SetKBHook) return(0);

    KillKBHook = (LPKillKBHook)GetProcAddress(hKBHookDLL, "KillKBHook");
    if (!KillKBHook) return(0);

    SetKBHook();

    return(1);
}

void FreeHookDLL()
{
    KillKBHook();
    FreeLibrary(hKBHookDLL);
}

int main()
{
    MSG msg;
    LoadHookDLL();

    while(!GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    FreeHookDLL();
}
