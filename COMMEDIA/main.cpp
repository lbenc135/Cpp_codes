#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXM 1000001

int cube[MAXM];
int m;


// NIJE TOCNO

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        scanf("%i", &m);
        int backm = m;
        m*=m*m;
        int x0, y0, z0;
        for(int i=0;i<m;i++)
        {
            scanf("%i", &cube[i]);
            if(cube[i]==0)
                {
                    x0=i/backm;
                    y0=i%backm;
                    z0=i/(backm*backm);
                }
        }

        int perm=x0+y0+z0+backm;
        for(int i=0;i<m;i++)
        {
            int r;
            if(i==m-1) r=0;
            else r = i+1;

            if(cube[i]!=r)
            {
                perm++;
                if(cube[i]!=0)
                    swap(cube[i], cube[cube[i]-1]);
                else
                    swap(cube[i], cube[m-1]);
                i--;
            }
        }

        if(perm%2)
            printf("Puzzle can be solved.\n");
        else
            printf("Puzzle is unsolvable.\n");
    }
}
