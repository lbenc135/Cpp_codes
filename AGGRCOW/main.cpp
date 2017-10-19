#include <cstdio>
#include <algorithm>
using namespace std;

int stalls[1000001];

int main()
{
    int n, c, t;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i %i", &n, &c);
        for(int i=0;i<n;i++)
            scanf("%i", &stalls[i]);
        sort(stalls, stalls+n);

        int l=stalls[0], h=stalls[n-1], m;
        while(l<h)
        {
            m=(l+h+1)/2;
            int maksc=1, prev=0;
            for(int i=1;i<n;i++)
            {
                if(stalls[i]-stalls[prev]>=m)
                {
                    maksc++;
                    prev=i;
                }
            }
            if(maksc>=c)
                l=m;
            else h=m-1;
        }
        printf("%i\n", l);
    }
}
