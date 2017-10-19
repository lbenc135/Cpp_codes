//KRIVO
#include <cstdio>
using namespace std;

int main()
{
    int p, k, t, n, mini, maxi, temp;
    for(int c=0;c<10;c++)
    {
        mini=1000000000; maxi=0;
        scanf("%i %i %i", &p, &k, &n);
        int a[n], b[n];
        for(int i=0;i<n;i++)
            scanf("%i %i", &a[i], &b[i]);

        for(int i=p;i<=k;i++)
        {
            temp=0;
            for(int j=0;j<n;j++)
                if(i>=a[j] && i<=b[j]) temp++;
            if(temp<mini) mini=temp;
            if(temp>maxi) maxi=temp;
        }
        if(mini==1000000000) mini=0;
        printf("%i %i\n", mini, maxi);
    }
}
