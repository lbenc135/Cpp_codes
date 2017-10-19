#include <windows.h>
#include <iostream>
using namespace std;

string winclass, winname, controlclass[10], upis;
int classes;

int main(int argc, char *argv[])
{
    cin >> classes;
    cin >> winclass;
    cin.get();
    getline(cin, winname);
    for(int i=0;i<classes;i++)
        cin >> controlclass[i];
    cin >> upis;

	cout << "Finding window.." << endl;
	HWND hwndWindow = FindWindow(winclass.c_str(), winname.c_str());

	if(NULL != hwndWindow)
    {
		cout << "Finding control.." << endl;
		HWND hwndControl = FindWindowEx(hwndWindow, NULL, controlclass[0].c_str(), NULL);
		for(int i=1;i<classes;i++)
            hwndControl = FindWindowEx(hwndControl, NULL, controlclass[i].c_str(), NULL);

		if(NULL != hwndControl)
		{
            SendMessage(hwndControl, WM_SETTEXT, NULL, (LPARAM)upis.c_str());
		}
		else cerr << "Control not found!" << endl;
	}
	else cerr << "Window not found!" << endl;
}
