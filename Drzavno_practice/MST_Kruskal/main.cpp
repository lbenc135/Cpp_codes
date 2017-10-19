#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
    edge() {}
    edge(int u1, int v1, int w1) { u=u1; v=v1; w=w1; }
};

int n, e;
vector<edge> g, mst;
int skup[1000], trs=1;

bool cmpEdge(const edge e1, const edge e2) { return e1.w<e2.w; }

void kruskal()
{
    sort(g.begin(), g.end(), cmpEdge);
    fill(skup+1, skup+n+1, -1);

    for(int i=0;mst.size()<n-1 && i<e;i++)
    {
        edge tr=g[i];
        if(skup[tr.u]!=skup[tr.v] || (skup[tr.u]==skup[tr.v] && skup[tr.u]==-1))
        {
            mst.push_back(tr);

            if(skup[tr.u]==-1 && skup[tr.v]==-1)
                skup[tr.u]=skup[tr.v]=trs++;
            else if(skup[tr.u]==-1) skup[tr.u]=skup[tr.v];
            else if(skup[tr.v]==-1) skup[tr.v]=skup[tr.u];
            else
            {
                int skup2=skup[tr.v];
                for(int j=1;j<=n;j++)
                    if(skup[j]==skup2)
                        skup[j]=skup[tr.u];
            }
        }
    }
}

int main()
{
    scanf("%i %i", &n, &e);
    for(int i=0;i<e;i++)
    {
        int u, v, w;
        scanf("%i %i %i", &u, &v, &w);
        g.push_back(edge(u, v, w));
    }

    kruskal();
    for(int i=0;i<mst.size();i++)
        printf("%i -> %i\n", mst[i].u, mst[i].v);
}
