#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define BUFSIZE 4096
#define CHILDNAME "child"

HANDLE g_hChildStd_IN_Rd = NULL;
HANDLE g_hChildStd_IN_Wr = NULL;
HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;

void CreateChildProcess(void);
void WriteToPipe(string);
void ReadFromPipe(void);

int main(int argc, TCHAR *argv[])
{
    SECURITY_ATTRIBUTES saAttr;

    printf("\n->Start of parent execution.\n");

    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0);
    SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0);
    CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0);
    SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0);
    CreateChildProcess();

    string input = "Primjer Example Test 123 Bok Lala";
    string app = "12345";

    WriteToPipe(input);

    int it=2;
    while(it--)
    {
        //WriteToPipe(input);
        printf( "\n->Contents %s written to child STDIN pipe.\n", input.c_str());

        printf("\n->Contents of child process STDOUT:\n\n");
        ReadFromPipe();

        cout << "Appending..." << endl;
        input.append(app);

    }

    printf("\n->End of parent execution.\n");

    return 0;
}

void CreateChildProcess()
{
   TCHAR szCmdline[]=TEXT(CHILDNAME);
   PROCESS_INFORMATION piProcInfo;
   STARTUPINFO siStartInfo;

   ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
   ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
   siStartInfo.cb = sizeof(STARTUPINFO);
   siStartInfo.hStdError = g_hChildStd_OUT_Wr;
   siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
   siStartInfo.hStdInput = g_hChildStd_IN_Rd;
   siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

   CreateProcess(NULL,
      szCmdline,     // command line
      NULL,          // process security attributes
      NULL,          // primary thread security attributes
      TRUE,          // handles are inherited
      0,             // creation flags
      NULL,          // use parent's environment
      NULL,          // use parent's current directory
      &siStartInfo,  // STARTUPINFO pointer
      &piProcInfo);  // receives PROCESS_INFORMATION
}

void WriteToPipe(string str)
{
    WriteFile(g_hChildStd_IN_Wr, str.c_str(), str.length(), NULL, NULL);
    FlushFileBuffers(g_hChildStd_IN_Wr);
    CloseHandle(g_hChildStd_IN_Wr);
}

void ReadFromPipe(void)
{
    CHAR chBuf[BUFSIZE]={0};
    bool success = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, NULL, NULL);
    FlushFileBuffers(g_hChildStd_OUT_Rd);
    if(success) cout << chBuf;
    cout << strlen(chBuf) << endl;;
}
