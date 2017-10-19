#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double zbroj=0;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        zbroj+=b[i];
    }

    int l;
    double d, veci=1000000, manji=-1000000;
    bool vece;
    for(int i=0;i<n-1;i++)
    {
        vece=true;
        l=b[i]-b[i+1];
        d=a[i+1]-a[i];
        if(l<0)
        {
            vece=false;
            l=-l;
            d=-d;
        }
        if(l==0)
        {
            if(d>0)
            {
                veci=-1000001;
                break;
            }
            continue;
        }
        d/=l;
        if(vece==true && d>manji)
            manji=d;
        if(vece==false && d<veci)
            veci=d;
    }
    if(veci<manji)
        cout << -1;
    else
        printf("%lf\n",zbroj*manji);
}
