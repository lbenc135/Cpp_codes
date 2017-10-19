#include <cstdio>
using namespace std;

#define MAXN 300000

int vals[MAXN];

int main()
{
    unsigned int n, m;
    scanf("%i %i", &n, &m);

    for(unsigned i=0;i<n;i++)
    {
        scanf("%i", &vals[i]);
    }

    unsigned sum=0, maxs=0, tail=0;
    for(unsigned i=0;i<n;i++)
    {
        sum+=vals[i];
        while(sum>m)
        {
            sum-=vals[tail];
            tail++;
        }
        if(sum>maxs)
            maxs=sum;
    }
    printf("%i\n", maxs);
}

