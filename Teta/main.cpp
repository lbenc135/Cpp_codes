#include <cstdio>
using namespace std;

int k, x, t;
int price[21], meni[21], jela[21];

inline void unos()
{
    int temp;
    scanf("%i", &k);
    for(int i=1;i<=k;i++)
        scanf("%i", &price[i]);
    scanf("%i", &x);
    for(int i=0;i<4;i++)
    {
        scanf("%i", &temp);
        meni[temp]++;
    }
    scanf("%i", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%i", &temp);
        jela[temp]++;
    }
}

int div_top(int a, int b)
{
    return (a+b-1)/b;
}

int main()
{
    unos();

    int uk=0;

    // Dodaj one kojih nema u meniju
    for(int i=1;i<=k;i++)
        if(!meni[i] && jela[i])
        {
            uk+=price[i]*jela[i];
            jela[i]=0;
        }

    int pmeni=0; // Potrebno menija za uzeti
    int cpos=0;             // Cijena ako ne uzmemo meni
    for(int i=1;i<=k;i++)
    {
        if(jela[i] && div_top(jela[i], meni[i])>pmeni)
            pmeni=div_top(jela[i], meni[i]);

        if(jela[i]) cpos+=jela[i]*price[i];
    }

    int minp=1000000000;
    for(int i=1;i<=pmeni;i++)
    {
        int pos=0;
        for(int m=0;m<i;m++)
            for(int j=1;j<k;j++)
                if(meni[j]) jela[j]-=meni[j];   // uzmi I menija

        for(int j=1;j<k;j++)
            if(jela[j]>0) pos+=jela[j]*price[j];    // plati preostala jela

        for(int m=0;m<i;m++)
            for(int j=1;j<k;j++)
                if(meni[j]) jela[j]+=meni[j];   // vrati na pocetno stanje

        if(pos+x*i<minp) minp=pos+x*i;
    }

    printf("%i\n", uk+minp);
}
