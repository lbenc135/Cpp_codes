#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2097152 //2^20

int t[MAXN];
int n, N=1;

void add(int v, int pos)
{
    pos+=N;
    t[pos]=v;
    for(pos/=2;pos>0;pos/=2)
        t[pos]=min(t[pos*2], t[pos*2+1]);
}

int query(int a, int b, int lo, int hi, int r=1)
{
    if(a<=lo && b>=hi) return t[r];
    if(b<lo || a>hi) return 1000000001;
    return  min(query(a, b, lo, (lo+hi)/2, r*2),
            query(a, b, (lo+hi)/2+1, hi, r*2+1));
}

int main()
{
    int q, ts;
    scanf("%i", &ts);
    for(int c=1;c<=ts;c++)
    {
        scanf("%i %i", &n, &q);
        while(N<n) N*=2;
        memset(t, 1000000001, 2*N*sizeof(int));
        int a, b;
        for(int i=0;i<n;i++)
        {
            scanf("%i", &a);
            add(a, i);
        }
        printf("Scenario #%i:\n", c);
        for(int i=0;i<q;i++)
        {
            scanf("%i %i", &a, &b);
            printf("%i\n", query(a-1, b-1, 0, N-1));
        }
    }
}
