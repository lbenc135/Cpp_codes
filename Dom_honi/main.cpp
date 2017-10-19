//PAO 1 TEST
#include <cstdio>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

bool visited[100001];
pii um[100001];
int n, m;

int binary(int p)
{
    int l=0, h=n, m;
    while(l<h)
    {
        m=(l+h)/2;
        if(um[m].first<p)
            l=m+1;
        else
            h=m;
    }
    return l;
}

int main()
{
    int p;
    scanf("%i %i %i", &n, &m, &p);
    int a, b;
    for(int i=0;i<n;i++)
    {
        scanf("%i %i", &a, &b);
        um[i]=pii(b, a);
    }
    sort(um, um+n);

    int rez=0;
    while(true)
    {
        int bnry=binary(p);
        if(um[bnry].first!=p)
            break;
        if(visited[bnry])
        {
            printf("-1\n");
            return 0;
        }
        visited[bnry]=true;
        p=um[bnry].second;
        rez++;
    }
    printf("%i\n", rez);
}
