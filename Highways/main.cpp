#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <functional>
using namespace std;

#define ppi pair<int,int>
#define MAXN 100001
#define INF 1000000000

int t, n, m, s, f, u, v, w;
vector<ppi > g[MAXN];
int d[MAXN];

int main()
{
    scanf("%i", &t);
    while(t--)
    {
        for(int i=0;i<MAXN;i++)
        {
            g[i].clear();
            d[i]=INF;
        }

        scanf("%i %i %i %i", &n, &m, &s, &f);
        for(int i=0;i<m;i++)
        {
            scanf("%i %i %i", &u, &v, &w);
            g[u].push_back(ppi(w, v));
            g[v].push_back(ppi(w, u));
        }

        d[s]=0;
        priority_queue<int, vector<int>, greater<int> > q;
        q.push(s);
        while(!q.empty())
        {
            u=q.top();
            q.pop();
            int sz=g[u].size();
            for(int i=0;i<sz;i++)
            {
                v=g[u][i].second;
                w=g[u][i].first;
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    q.push(v);
                }
            }
        }

        if(d[f]==INF) printf("NONE\n");
        else printf("%i\n", d[f]);
    }
}
