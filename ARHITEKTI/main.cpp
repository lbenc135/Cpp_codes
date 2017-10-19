#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 100000000000000000

struct arhitekt {
    long long k, s, sum;
};

bool compareArch(const arhitekt &a, const arhitekt &b)
{ return a.sum<b.sum; }

int main()
{
    int n;
    scanf("%i", &n);
    long long k, s;
    arhitekt archs[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lli %lli", &k, &s);
        archs[i].k = k;
        archs[i].s = s;
        archs[i].sum = k*s;
    }

    sort(archs, archs+n, compareArch);

    int num_grupa=0, minit;
    long long diff, mindiff;


    for(int i=0;i<n;i++)
    {
        mindiff=INF;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            diff = max(archs[i].k, archs[j].k)*max(archs[i].s, archs[j].s) - archs[j].sum;
            if(diff<mindiff)
            {
                mindiff = diff;
                minit = j;
            }
        }

        if(mindiff<archs[i].sum)
        {
            archs[minit].k = max(archs[i].k, archs[minit].k);
            archs[minit].s = max(archs[i].s, archs[minit].s);
            archs[minit].sum  = archs[minit].k*archs[minit].s;
            archs[i].sum=-INF;
        }
    }

    long long sum=0;
    for(int i=0;i<n;i++)
        if(archs[i].sum!=-INF) sum+=archs[i].sum;

    printf("%lli", sum);
}
