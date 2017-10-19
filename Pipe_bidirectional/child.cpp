#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    string str, str2, str3;

    cout << "Started child..." << endl;

    while(1)
    {
        cin >> str >> str2;
        cout << str + str2 << endl;
    }

    return 0;
}
