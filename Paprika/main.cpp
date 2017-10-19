#include <cstdio>
using namespace std;

int main()
{
    int n, x;
    int a[1001], b[1001];
    scanf("%i %i", &n, &x);
    for(int i=0;i<n;i++)
        scanf("%i %i", &a[i], &b[i]);

    for(int i=1;i<n;i++)
    {
        if(b[i-1]==0 && b[i]==1 && a[i]>a[i-1])
        {
            a[i-1]^=a[i];
            a[i]^=a[i-1];
            a[i-1]^=a[i];
        }
        else if(b[i-1]==1 && b[i]==0 && a[i]<a[i-1])
        {
            a[i-1]^=a[i];
            a[i]^=a[i-1];
            a[i-1]^=a[i];
        }
    }

    int fld=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]==0 && a[i]>x) fld++;
        else if(b[i]==1 && a[i]<=x) fld++;
    }
    printf("%i\n", fld);
}
