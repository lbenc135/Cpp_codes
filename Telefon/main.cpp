#include <iostream>
using namespace std;

int main()
{
    char zn[20];
    cin >> zn;
    char x[20], pt=0;
    cin >> x;
    for(int i=0;i<20;i++)
    {
        if(zn[i]=='x') {cout << x[pt]; pt++;}
        else if(zn[i]=='-') cout << '-';
    }
}
