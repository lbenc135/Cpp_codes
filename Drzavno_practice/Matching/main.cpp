#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, e;
vector<int> g[100];
bool visited[100];
int par[100];

bool spari(int x)
{
    visited[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int cura=g[x][i];
        if(par[cura]==-1 || (!visited[par[cura]] && spari(par[cura])))
        {
            par[cura]=x;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%i %i", &n, &e);
    for(int i=0;i<e;i++)
    {
        int u, v;
        scanf("%i %i", &u, &v);
        g[u].push_back(v);
    }

    int rj=0;
    fill(par, par+100, -1);
    for(int i=1;i<=n;i++)
    {
        fill(visited, visited+100, 0);
        rj+=spari(i);
    }
    printf("%i\n", rj);
}
