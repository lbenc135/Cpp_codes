#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define loc pair<int,int>
#define INF 1000000000

int n;
vector<loc > g;
vector<loc > temp;

int calcDist(int x, int y, int x2, int y2)
{
    return abs(x-x2)+abs(y-y2);
}

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        g.clear();
        temp.clear();
        int u, v;
        scanf("%i", &n);
        int minx=INF, maxx=0, miny=INF, maxy=0;
        for(int i=0;i<n;i++)
        {
            scanf("%i %i", &u, &v);
            g.push_back(pair<int, int>(u, v));
            if(u<minx) minx=u;
            if(u>maxx) maxx=u;
            if(v<miny) miny=v;
            if(v>maxy) maxy=v;
        }

        int midx=(maxx-minx)/2, midy=(maxy-miny)/2;
        for(int i=0;i<n;i++)
        {
            int d=calcDist(midx, midy, g[i].first, g[i].second);
            temp.push_back(loc(d, i));
        }
        sort(temp.begin(), temp.end());
        long long total, mint=INF;
        int gr=min(350, n);
        for(int j=0;j<gr;j++)
        {
            total=0;
            for(int i=0;i<n;i++)
            {
                total+=calcDist(g[i].first, g[i].second, g[temp[j].second].first, g[temp[j].second].second);
            }
            if(total<mint) mint=total;
        }

        printf("%lli\n", mint);
    }
}

