#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, znamenki, temp;
    cin >> n;
    temp=n;
    for(int i=0;temp>0;i++)
    {
        znamenki=i;
        temp/=10;
    }
    int zn[znamenki];
    temp=n;
    for(int i=0;temp>0;i++)
    {
        zn[i]=temp%10;
        temp/=10;
    }
    int zbroj=0;
    for(int i=1;zbroj<n;i++)
    {
        zbroj=0;
        for(int j=0;j<=znamenki;j++)
            zbroj+=pow(zn[j], i);
        if(zbroj==n) {cout << i; return 0;}
    }
    cout << 0;
}
