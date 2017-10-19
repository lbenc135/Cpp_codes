#include<cstdio>
#include<cmath>
using namespace std;

long long comb(int n,int r);

long long a[65][65];

int main()
{
    long long n;
    int p, t;
    for(int i=0;i<65;i++)
    {
        for(int j=0;j<65;j++)
        {
            if(i==j)
                a[i][j]=1;
            else if(j==0)
                a[i][j]=1;
            else
                a[i][j]=-1;
        }
    }
    scanf("%d",&t);
    for(int c=0;c<t;c++)
    {
        scanf("%lli",&n);
        if(n==1||n==2)
            printf("%lli\n",n);
        else
        {
            p=3;
            while(true)
            {
                long long s=comb(p,ceil(p/2));
                if(n>s)
                    p++;
                else
                    break;
            }
            printf("%i\n",p);
        }

    }
}

long long comb(int n,int r)
{
    if(n==r || r==0)
        return 1;
    else
    {
        if(a[n][r]!=-1)
            return a[n][r];
        else
        {
            a[n][r]=comb(n-1,r-1)+comb(n-1,r);
            return a[n][r];
        }
    }
}
