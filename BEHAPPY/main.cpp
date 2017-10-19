#include <cstdio>
#include <utility>
using namespace std;

#define ull unsigned long long
#define pii pair<int,int>

int n, m;
pii g[21];

ull rec(int girl, int gifts)
{
    if(girl==m-1 && gifts>=g[girl].first && gifts<=g[girl].second)
        return 1;
    else if(girl==m-1) return 0;

    ull rez=0;
    for(int i=g[girl].first;i<=g[girl].second;i++)
    {
        if(i<=gifts)
            rez+=rec(girl+1, gifts-i);
    }
    return rez;
}

int main()
{
    while(1)
    {
        scanf("%i %i", &m, &n);
        if(m==0 && n==0) break;
        for(int i=0;i<m;i++)
            scanf("%i %i", &g[i].first, &g[i].second);

        printf("%llu\n", rec(0, n));
    }
}
