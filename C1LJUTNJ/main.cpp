#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long

int w[100001];

int main()
{
    int m, n;
    scanf("%i %i", &m, &n);
    ll sum=0, rez=0;
    for(int i=0;i<n;i++)
    {
        scanf("%i", &w[i]);
        sum+=w[i];
    }
    sum-=m;
    sort(w, w+n);
    for(int i=0;i<n;i++)
    {
        ll a=min(sum/(n-i), (ll)w[i]);
        sum-=a;
        rez+=a*a;
    }
    printf("%lli\n", rez);
    return 0;
}
