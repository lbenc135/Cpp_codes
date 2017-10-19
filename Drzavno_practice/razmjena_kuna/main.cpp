#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double k[100], e[100], t[100];

int main()
{
    scanf("%lf %i", &k[0], &n);
    for(int i=0;i<n;i++)
        scanf("%lf", &t[i]);

    for(int i=0;i<n;i++)
    {
        k[i+1]=max(k[i], e[i]*t[i]);
        e[i+1]=max(e[i], k[i]*(1.0/t[i]));
    }
    printf("%lf\n", k[n]);
}
