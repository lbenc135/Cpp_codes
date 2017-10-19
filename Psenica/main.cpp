#include <cstdio>
#include <queue>
using namespace std;

struct vlat {
    int visina, kolicina;
    vlat () {}
    vlat (int v, int k) {
        visina = v;
        kolicina = k;
    }
};

int n, cnt[100001];

deque <vlat> DQ;

int main()
{
    int a;
    scanf("%i", &n);
    for (int i=0;i<n;i++) {
        scanf("%i", &a);
        cnt[a]++;
    }

    for (int i=1;i<=100000;i++)
        if (cnt[i])
            DQ.push_back(vlat(i, cnt[i]));

    bool mirko=true;

    while(DQ.size()>2)
    {
        if(DQ.front().kolicina<DQ.back().kolicina)
        {
            vlat mala = DQ.front(), velika = DQ.back();
            DQ.pop_front(); DQ.pop_back();

            DQ.front().kolicina += mala.kolicina;
            velika.kolicina -= mala.kolicina;
            DQ.back().kolicina += mala.kolicina;

            if(DQ.size()==1) mirko=false;

            DQ.push_back(velika);
        }
        else if(DQ.front().kolicina==DQ.back().kolicina)
        {
            if(DQ.size()==3)
            {
                DQ.pop_front();
                mirko=false;
            }
            else
            {
                int h = DQ.back().kolicina;
                DQ.pop_front(); DQ.pop_back();
                DQ.back().kolicina += h;
                DQ.front().kolicina += h;
            }
        }
        else
        {
            vlat mala = DQ.front(), velika = DQ.back();
            DQ.pop_front(); DQ.pop_back();

            DQ.back().kolicina += velika.kolicina;
            mala.kolicina -= velika.kolicina;
            DQ.front().kolicina += velika.kolicina;

            if(DQ.size()==1) mirko=false;

            DQ.push_front(mala);
        }
    }


    if (mirko) printf("Slavko\n");
    else printf("Mirko\n");
    printf("%i %i\n", DQ.front().visina, DQ.back().visina);
}
