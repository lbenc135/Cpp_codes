#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, temp;
    while(1)
    {
        scanf("%i", &n);
        if(n==-1) return 0;
        if(n%2)
        {
            n--;
            if(n%3==0)
            {
                n=n/3*4+1;
                temp=sqrt(n);
                if(temp*temp==n)
                {
                    if(temp%2)
                    {
                        printf("Y\n");
                        continue;
                    }
                }
            }
        }
        printf("N\n");
    }
}
