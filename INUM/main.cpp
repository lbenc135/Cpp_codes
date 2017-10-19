#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAXN 100000

void closest();

int n;
long long a[MAXN];
long long mincnt, maxcnt;

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%lli", &a[i]);

    closest();

    printf("%lli %lli", mincnt, maxcnt);
}

void closest()
{
    sort(a, a+n);
    long long mindiff=a[1]-a[0], maxdiff=0;
    //WRONG!! moze biti n^2 minimumi
    for(int i=1;i<n;i++)
    {
        long long diff = a[i]-a[i-1];
        if(diff<mindiff) {
            mincnt=1;
            mindiff = diff;
        } else if(diff==mindiff)
            mincnt++;
    }

    for(int i=0;i<n;i++)
    {
        if(i>0 && a[i]>a[i-1])
            break;
        for(int j=n-1;j>=0;j--)
        {
            long long diff = a[j]-a[i];
            if(diff>maxdiff)
            {
                maxdiff = diff;
                maxcnt = 1;
            } else if(diff==maxdiff)
                maxcnt++;
            else break;
        }
    }
}
