#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000010

int f[MAXN], g[MAXN];
char d[MAXN];

int main()
{
    int n;
    scanf("%i %s", &n, &d);

    for(int i=1;i<=n;i++)
    {
        if(d[i-1]=='A') {
            f[i] = f[i-1];
            g[i] = min(f[i-1], g[i-1]) + 1;
        } else {
            g[i] = g[i-1];
            f[i] = min(f[i-1], g[i-1]) + 1;
        }
    }
    printf("%i\n", f[n]);
}
