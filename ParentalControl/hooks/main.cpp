#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "main.h"

#pragma data_seg("Shared")
HHOOK hhook = NULL;
#pragma data_seg()

HINSTANCE g_hInstance = NULL;

_declspec(dllexport) LRESULT CALLBACK LLHook (int nCode , WPARAM wParam , LPARAM lParam)
{
    KBDLLHOOKSTRUCT *str = (KBDLLHOOKSTRUCT *)lParam;

    bool ctrlDown = GetAsyncKeyState(VK_CONTROL) & 0x8000;

    if(str->vkCode == VK_F12 && ctrlDown)
    {
        INPUT ctrlV[4];
        ZeroMemory(ctrlV, sizeof(ctrlV));

        ctrlV [0].type = INPUT_KEYBOARD;
        ctrlV [0].ki.wVk = VK_CONTROL;

        ctrlV [1].type = INPUT_KEYBOARD;
        ctrlV [1].ki.wVk = VK_F12;

        ctrlV [2].type = INPUT_KEYBOARD;
        ctrlV [2].ki.wVk = VK_F12;
        ctrlV [2].ki.dwFlags = KEYEVENTF_KEYUP;

        ctrlV [3].type = INPUT_KEYBOARD;
        ctrlV [3].ki.wVk = VK_CONTROL;
        ctrlV [3].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput (4, ctrlV, sizeof (INPUT));
    }
    else if(str->vkCode == VK_SHIFT || str->vkCode == VK_RETURN || str->vkCode == VK_BACK || (str->vkCode>=0x30 && str->vkCode<=0x39) || (str->vkCode>=0x41 && str->vkCode<=0x5A))
        return CallNextHookEx(hhook, nCode, wParam, lParam);

    return 1;
}

_declspec(dllexport) void SetKBHook()
{
 if (!hhook) hhook = SetWindowsHookEx(WH_KEYBOARD_LL, LLHook, g_hInstance, 0);
}

_declspec(dllexport) void KillKBHook()
{
 if(hhook) UnhookWindowsHookEx(hhook);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            g_hInstance = hinstDLL;
            break;

        case DLL_PROCESS_DETACH:
            KillKBHook();
            break;

        case DLL_THREAD_ATTACH:
            g_hInstance = hinstDLL;
            break;

        case DLL_THREAD_DETACH:
            KillKBHook();
            break;
    }
    return TRUE;
}
