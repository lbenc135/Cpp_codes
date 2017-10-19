//KRIVO
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100001
#define pii pair<int,int>
#define INF 1000000000

int n, l, s, N=1;
int a[MAXN];

pii t[262144]; //2^18

void add(int v, int pos)
{
    pos+=N;
    t[pos].first=t[pos].second=v;
    for(pos/=2;pos>0;pos/=2)
    {
        t[pos].first=min(t[pos*2].first, t[pos*2+1].first);
        t[pos].second=max(t[pos*2].second, t[pos*2+1].second);
    }
}

pii query(int a, int b, int lo=0, int hi=N-1, int r=1)
{
    if(a<=lo && b>=hi) return t[r];
    if(b<lo || a>hi) return pii(INF, -INF);
    pii fr = query(a, b, lo, (lo+hi)/2, r*2);
    pii sc = query(a, b, (lo+hi)/2+1, hi, r*2+1);
    return pii(min(fr.first, sc.first), max(fr.second, sc.second));
}

int main()
{

    for(int i=0;i<262144;i++)
        t[i] = pii(INF, -INF);
    scanf("%i %i %i", &n, &s, &l);
    while(N<n) N*=2;
    for(int i=0;i<n;i++)
    {
        scanf("%i", &a[i]);
        add(a[i], i);
    }

    int lo=0, rez=0;
    pii p;
    for(int i=1;i<n;i++)
    {
        p = query(lo, i);
        if(p.second-p.first>s)
        {
            if(i-lo>=l)
            {
                lo=i;
                rez++;
            }
            else
            {
                do
                {
                    lo++;
                    p = query(lo, i);
                } while(p.second-p.first>s);
            }
        }
    }
    if(n-lo>=l && p.second-p.first<=s)
        rez++;

    if(!rez) rez=-1;
    printf("%i\n", rez);
}
