#include <iostream>

using namespace std;

int main()
{
    int r, n;
    string s;
    cin>>r>>s>>n;
    string f[50];
    for(int i=0;i<n;i++)
        cin >> f[i];
    int sm=0, ms=0;
    for(int i=0;i<r;i++)
    {
        int t[3]={0};
        for(int j=0;j<n;j++)
        {
            if(s[i]=='S' && f[j][i]=='P')sm+=2;
            else if(s[i]=='S' && f[j][i]=='S')sm++;
            else if(s[i]=='P' && f[j][i]=='R')sm+=2;
            else if(s[i]=='P' && f[j][i]=='P')sm++;
            else if(s[i]=='R' && f[j][i]=='S')sm+=2;
            else if(s[i]=='R' && f[j][i]=='R')sm++;
            if(f[j][i]=='P')t[0]++;
            else if(f[j][i]=='S')t[1]++;
            else if(f[j][i]=='R')t[2]++;
        }
        int ms1=t[0]*2+t[1],
            ms2=t[1]*2+t[2],
            ms3=t[2]*2+t[0];
        ms+=max(ms1, max(ms2, ms3));
    }
    cout<<sm<<endl<<ms<<endl;
}
