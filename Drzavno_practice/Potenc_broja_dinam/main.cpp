#include <cstdio>
#include <cstring>
using namespace std;

int stanje[100];

int smalldiv(int a)
{
    for(int i=2;i<=a;i++)
        if(a%i==0) return i;
}

int mincost(int n)
{
    if(n<=1) return 0;
    if(stanje[n]!=-1) return stanje[n];

    int rj=10000000;
    for(int i=1;i<n;i++)
    {
        if(mincost(n-i)+mincost(i)+1<rj)
            rj=mincost(n-i)+mincost(i)+1;
    }
    int s=smalldiv(n);
    if(mincost(n/s)+s-1<rj)
        rj=mincost(n/s)+s-1;
    return rj;
}

int main()
{
    int n;
    memset(stanje, -1, sizeof(stanje));

    scanf("%i", &n);
    printf("%i\n", mincost(n));
}
