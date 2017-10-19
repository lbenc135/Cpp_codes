#include <cstdio>
#include <algorithm>
using namespace std;

int sticks[2001];

int main()
{
    int n;
    long long rez;
    while(true)
    {
        rez=0;
        scanf("%i", &n);
        if(!n) break;
        for(int i=0;i<n;i++)
            scanf("%i", &sticks[i]);

        sort(sticks, sticks+n);
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
            {
                rez+=n-(lower_bound(sticks, sticks+n, sticks[i]+sticks[j]+1)-sticks);
            }
        printf("%lli\n", rez);
    }
}
