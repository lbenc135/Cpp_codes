#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 201
#define INF 1000000000

int n, m, k, q;
int mind[MAX][MAX];

int main()
{
    int u, v, d, a, b;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            if(i!=j)
                mind[i][j]=INF;

    scanf("%i %i %i %i", &n, &m, &k, &q);
    for(int i=0;i<m;i++)
    {
        scanf("%i %i %i", &u, &v, &d);
        mind[u][v] = d;
    }

    for (int x=1; x<=n; x++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                    mind[i][j]=min(mind[i][j],mind[i][x]+mind[x][j]);

    long long sum=0;
    int posib=0;
    for(int i=0;i<q;i++)
    {
        scanf("%i %i", &a, &b);
        int cost=INF;
        for(int j=1;j<=k;j++)
            cost=min(cost, mind[a][j]+mind[j][b]);
        if(cost!=INF)
        {
            sum+=cost;
            posib++;
        }
    }

    printf("%i\n%lli\n", posib, sum);
}
