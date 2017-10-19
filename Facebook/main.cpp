#include <cstdio>
#include <vector>
using namespace std;

bool visited[100001];
vector<int> g[100001];
long long nodes;

long long DFS(int a)
{
    if(visited[a]) return 0;
    visited[a]=true;
    nodes++;
    long long rez=g[a].size();
    for(int i=0;i<g[a].size();i++)
        rez+=DFS(g[a][i]);
    return rez;
}

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    int a, b;
    for(int i=0;i<m;i++)
    {
        scanf("%i %i", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long rez=0;
    for(int i=1;i<=n;i++)
    {
        long long d = DFS(i);
        if(nodes==0) continue;
        rez+=(nodes*(nodes-1)-d)/2;
        nodes=0;
    }
    printf("%lli\n", rez);
}
