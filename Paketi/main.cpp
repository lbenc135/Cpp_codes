#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    int x[n], maks=0, zbroj=0, mini=1000000000;
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
        if(x[i]>maks) maks=x[i];
        if(x[i]<mini) mini=x[i];
        zbroj+=x[i];
    }

    long long l=3*maks, h=3*zbroj+maks*maks-mini*mini, mid;
    long long pak, kap;
    while(l<h)
    {
        pak=0; maks=mini=x[0]; zbroj=0; kap=0;
        mid=(l+h)/2;
        for(int i=0;i<n;i++)
        {
            zbroj+=x[i];
            kap+=3*x[i];
            if(x[i]>maks) {kap-=maks*maks; maks=x[i]; kap+=maks*maks;}
            if(x[i]<mini) {kap+=mini*mini; mini=x[i]; kap-=mini*mini;}
            if(kap>mid)
            {
                pak++;
                kap=3*x[i]; maks=mini=x[i];
            }
        }
        if(p==++pak) h=mid;
        else if(pak<p) h=mid;
        else l=mid+1;
    }
    cout << h;
}
