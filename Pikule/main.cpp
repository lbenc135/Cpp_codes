#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, m, k, temp, q, x, s, rj=0;
    long long tlo=0;
    scanf("%i %i %i", &n, &m, &k);
    bool postoji[n];
    memset(postoji, 1, sizeof(postoji));
    for(int i=0;i<k;i++)
    {
        scanf("%i", &temp);
        postoji[temp]=0;
    }
    scanf("%i", &q);
    int epruveta[n+1];
    memset(epruveta, 0, sizeof(epruveta));
    for(int c=0;c<q;c++)
    {
        scanf("%i %i", &x, &s);
        while(s>0)
        {
            if(!postoji[x]) {tlo+=s; break;}
            if(epruveta[x]==0) rj++;
            temp=s;
            s-=m-epruveta[x];
            epruveta[x]+=temp;
            if(epruveta[x]>m)
            {
                epruveta[x]=m;
                x++;
            }
        }
    }

    printf("%i %i", rj, tlo);
}
