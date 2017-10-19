#include <windows.h>
using namespace std;

int main()
{
    HANDLE mutex = CreateMutexA(0, 1, "mut");

    while(true)
    {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        ZeroMemory( &pi, sizeof(pi) );

        // Start the child process.
        CreateProcess( NULL,   // No module name (use command line)
            "SysWow.exe namesys",        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            CREATE_NO_WINDOW | CREATE_NEW_PROCESS_GROUP,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory
            &si,            // Pointer to STARTUPINFO structure
            &pi );           // Pointer to PROCESS_INFORMATION structure

            WaitForSingleObject(pi.hProcess, INFINITE);

            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
    }
}
