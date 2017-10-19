#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        int s, f;
        scanf("%i %i", &s, &f);
        int stamps[1001];
        for(int i=0;i<f;i++)
            scanf("%i", &stamps[i]);
        sort(stamps, stamps+f);
        int res = 0, has = 0;
        for(int i=f-1;i>=0;i--)
        {
            if(has>=s)
                break;
            has+=stamps[i];
            res++;
        }
        if(has>=s)
            printf("Scenario #%i:\n%i\n\n", c+1, res);
        else
            printf("Scenario #%i:\nimpossible\n\n", c+1);
    }
}
