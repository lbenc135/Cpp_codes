#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n[6]={0,0,0,0,0,0};
    int k[5],maxn=0;
    cin >> k[0] >> k[1] >> k[2] >> k[3] >> k[4];
    for(int i=0;i<5;i++)
        n[k[i]]++;
    for(int i=0;i<6;i++)
        if(n[i]>maxn) maxn = n[i];
    cout << maxn;
}
