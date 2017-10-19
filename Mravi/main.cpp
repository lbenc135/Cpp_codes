#include <cstdio>
#include <utility>
using namespace std;

#define pii pair<int,int>

pii polje[1000][1000];
int k[1000];
int n;

bool check(int it, double v)
{
    if(k[it]!=-1)
    {
        if(v>=k[it]) return true;
        else return false;
    }
    else
    {
        bool moze=true;
        for(int i=1;i<=n;i++)
            if(polje[it][i].first!=0)
            {
                double val=v*polje[it][i].first/100;
                if(polje[it][i].second==1)
                    val*=val;
                if(!check(i, val)) {moze=false; break;}
            }

        if(moze) return true;
        else return false;
    }
}

int main()
{
    int a, b;
    scanf("%i", &n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%i %i", &a, &b);
        scanf("%i %i", &polje[a][b].first, &polje[a][b].second);
    }
    for(int i=1;i<=n;i++)
        scanf("%i", &k[i]);

    double l=1, h=1000000000, mid;
    while(l<h)
    {
        if(h-l<0.00001) break;
        mid=(l+h)/2;
        if(check(1, mid)) h=mid;
        else l=mid+0.00001;
    }
    printf("%.3lf", l);
}
