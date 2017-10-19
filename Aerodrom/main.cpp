#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    int t[100000];
    for(int i=0;i<n;i++)
        scanf("%i", &t[i]);

    long long l=0, h=1000000000000000000L, mid;
    while(l<h)
    {
        mid=(l+h)/2;
        long long rez=0;
        for(int i=0;i<n;i++)
            rez+=mid/t[i];
        if(rez<m)
            l=mid+1;
        else
            h=mid;
    }
    printf("%lli", l);
}
