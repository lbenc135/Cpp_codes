#include <cstdio>

using namespace std;

int main()
{
    int a, d;
    while(true)
    {
        scanf("%i %i", &a, &d);
        if(a==0 && d==0) break;
        int adist[12], ddist[12], mina=100000, mind=10000, mind2;
        for(int i=0;i<a;i++) {
            scanf("%i", &adist[i]);
            if(adist[i]<mina) mina=adist[i];
        }
        for(int i=0;i<d;i++) {
            scanf("%i", &ddist[i]);
            if(ddist[i]<=mind) {
                mind2 = mind;
                mind = ddist[i];
            } else if(ddist[i]<mind2)
                mind2 = ddist[i];
        }
        if(mina<mind2)
            printf("Y\n");
        else
            printf("N\n");
    }
}
