#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, b1, b2;
    cin >> n;
    string imena[n];
    for(int i=0;i<n;i++)
    {
        cin >> imena[i];
        if(imena[i]=="BLJTV1") b1=i;
        if(imena[i]=="BLJTV2") b2=i;
    }

    if(b1>b2) b2++;
    for(int i=0;i<b1;i++)
        cout << 1;
    for(int i=0;i<b1;i++)
        cout << 4;
    for(int i=0;i<b2;i++)
        cout << 1;
    for(int i=1;i<b2;i++)
        cout << 4;
}
