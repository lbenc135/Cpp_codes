#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define pii pair<int,int>

vector<pii > g[300001];
bool info[100001];
bool visited[100001];

bool BFS(int k)
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        bool b=info[t];
        int l=g[t].size();
        for(int i=0;i<l;i++)
        {
            if(g[t][i].second>k) continue;
            int s=g[t][i].first;
            if(!visited[s])
            {
                q.push(s);
                info[s]=!info[t];
                visited[s]=true;
            }
            else if(b==info[s])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    for(int i=0;i<m;i++)
    {
        int a, b;
        scanf("%i %i", &a, &b);
        g[a].push_back(pii(b, i+1));
        g[b].push_back(pii(a, i+1));
    }

    int l=0, h=m, mid;
    while(l<h)
    {
        memset(visited, 0, sizeof(visited));
        memset(info, 0, sizeof(info));
        visited[1]=true;

        mid=(l+h)/2;
        if(BFS(mid))
            l=mid+1;
        else
            h=mid;
    }
    printf("%i", l);
}
