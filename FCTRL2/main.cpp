#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int i, k=0, j, carry=0, arr[1000]={1};
        scanf("%d",&n);
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                arr[j]=arr[j]*i+carry;
                carry=arr[j]/10;
                arr[j]%=10;
            }
            while(carry)
            {
                k++;
                arr[k]=carry%10;
                carry/=10;
            }
        }
        for(i=k;i>=0;i--)
            printf("%i", arr[i]);
        printf("\n");
    }
    return 0;
}
