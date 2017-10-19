#include <iostream>
using namespace std;

int main()
{
    char n[200];
    int nop=0;
    cin >> n;
    for(int i=0;i<200;i++)
    {
        if(n[i]<65 || n[i]>122) break;
        if(n[i]>=65 && n[i]<=90 && (i+nop)%4!=0) nop+=4-(i+nop)%4;
    }
    cout << nop;
}
