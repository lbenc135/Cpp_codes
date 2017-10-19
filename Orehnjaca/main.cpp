#include <iostream>
using namespace std;

int main()
{
    int l, n, maks=0, br;
    cin >> l >> n;
    int p[n], k[n];
    for(int i=0;i<n;i++)
    {
        cin >> p[i] >> k[i];
        if(k[i]-p[i]>maks) {maks=k[i]-p[i]; br=i+1;}
    }

    cout << br << endl;
    maks=0;
    bool oreh[l];
    int pl;
    for(int i=0;i<l;i++)
        oreh[i]=false;
    for(int i=0;i<n;i++)
    {
        br=0;
        for(int j=p[i];j<=k[i];j++)
            if(oreh[j]==false) {br++; oreh[j]=true;}
        if(br>maks) {maks=br; pl=i+1;}
    }
    cout << pl;
}
