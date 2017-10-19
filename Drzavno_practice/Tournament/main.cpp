#include <cstdio>
using namespace std;

int n, N=1;
int tree[1000000];

void add(int p, int v)
{
    p+=N;
    for(;p>0;p/=2)
        tree[p]+=v;
}

int query(int a, int b, int lo=0, int hi=N-1, int c=1)
{
    if(a>=lo && b<=hi) return tree[c];
    if(b<lo || a>hi) return 0;
    int mid=(lo+hi)/2;
    return query(a, b, lo, mid, c*2) +
           query(a, b, mid+1, hi, c*2+1);
}

int main()
{
    scanf("%i", &n);
    while(N<n) N*=2;

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i", &a);
        add(i, a);
    }

    printf("%i\n", query(0, n-1));
}
