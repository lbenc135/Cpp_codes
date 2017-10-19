//KRIVO
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> niz;
pair<int,int> best[201];

int rast()
{
    int sol=0;
    for(int i=0;i<n;i++)
    {
        best[i].first=100000000;
        int j;
        for(j=0;best[j].first<niz[i];j++)
            ;
        if(best[j].first!=niz[i])
        {
            best[j].first=niz[i];
            best[j].second=i;
        }

        sol=max(sol, j+1);
    }
    return sol;
}

int pad()
{
    int sol=0;
    for(int i=0;i<n;i++)
    {
        best[i].first=0;
        int j;
        for(j=0;best[j].first>niz[i];j++)
            ;
        if(best[j].first!=niz[i])
        {
            best[j].first=niz[i];
            best[j].second=i;
        }

        sol=max(sol, j+1);
    }
    return sol;
}

int main()
{
    while(true)
    {
        scanf("%i", &n);
        if(n==-1) break;
        niz.clear(); niz.resize(n);
        for(int i=0;i<n;i++)
            scanf("%i", &niz[i]);

        int r=rast();
        for(int i=0;i<r;i++)
            niz.erase(niz.begin()+best[i].second-i);
        int p=pad();
        printf("%i\n", n-r-p);
    }
    return 0;
}
