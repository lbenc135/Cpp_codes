#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    for(int c=0;c<t;c++)
    {
        int sum=1;
        int n, sr;
        scanf("%i",&n);
        if(n<2)
            printf("0\n");
        else
        {
            sr = sqrt(n);
            for(int i=2;i<=sr;i++) {
                if(n%i==0)
                    sum+=i + n/i;
            }
            if(sr*sr==n) sum-=sr;
            printf("%i\n", sum);
        }
    }
}
