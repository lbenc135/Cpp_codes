#include <cstdio>
using namespace std;

int main()
{
    long long t, n, sum, temp;
    scanf("%lli", &t);
    while(t--)
    {
        scanf("%lli", &n);
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lli", &temp);
            sum+=temp;
            sum%=n;
        }
        if(sum%n) printf("NO\n");
        else printf("YES\n");
    }
}
