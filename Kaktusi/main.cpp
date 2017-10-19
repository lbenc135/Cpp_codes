#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    char s[n-1];
    int raspored[n];
    raspored[0]=1;
    for(int i=0;i<n-1;i++)
        {cin >> s[i]; raspored[i+1]=i+2;}

    bool moze;
    raspored[0]=k+1;
    raspored[k]=1;
    do
    {
        moze=true;
        for(int i=0;i<n-1;i++)
            if(s[i]=='N' && raspored[i+1]>raspored[i] || s[i]=='D' && raspored[i+1]<raspored[i]) moze=false;
        if(moze) break;
    } while(next_permutation(raspored, raspored+n));

    for(int i=0;i<n;i++)
        cout << raspored[i] << " ";
}
