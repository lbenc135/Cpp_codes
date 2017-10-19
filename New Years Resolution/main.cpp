#include <cstdio>
using namespace std;

int t, n, gp, gc, gf, p[21], c[21], f[21];
bool sol[21];

int main()
{
    scanf("%i", &t);
    for(int cs=0;cs<t;cs++)
    {
        scanf("%i %i %i", &gp, &gc, &gf);
        scanf("%i", &n);
        for(int i=0;i<n;i++)
            scanf("%i %i %i", &p[i], &c[i], &f[i]);

        int bm=0;
        bool can=0;
        while(bm<(1<<n))
        {
            int tp=0, tc=0, tf=0;
            for(int i=0;i<n;i++)
                if(bm&(1<<i))
                {
                    tp+=p[i];
                    tc+=c[i];
                    tf+=f[i];
                }
            bm++;
            if(tp>gp || tc>gc || tf>gf) continue;
            if(tp==gp && tc==gc && tf==gf)
            {
                can=1;
                break;
            }
        }
        sol[cs]=can;
    }
    for(int cs=0;cs<t;cs++)
        if(sol[cs]) printf("Case #%i: yes\n", cs+1);
        else printf("Case #%i: no\n", cs+1);
}
