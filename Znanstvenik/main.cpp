#include <cstdio>
#include <map>
using namespace std;

#define ull unsigned long long
#define BAS 3137

int r, c;
ull B[1001]={1, BAS};
char table[1001][1001];

void init()
{
    for(int i=2;i<=1000;i++)
        B[i]=B[i-1]*BAS;
}

ull calchash(int s, int p)
{
    ull rez=0;
    for(int i=p;i<r;i++)
        rez+=table[i][s]*B[i];
    return rez;
}

bool canremove(int p)
{
    map<ull, bool> m;
    for(int i=0;i<c;i++)
    {
        ull h=calchash(i, p);
        if(m[h]) return false;
        else m[h]=true;
    }
    return true;
}

int main()
{
    scanf("%i %i", &r, &c);
    for(int i=0;i<r;i++)
        scanf("%s", &table[i]);

    init();

    int l=1, h=r, mid;
    while(l<h)
    {
        mid=(l+h)/2;
        if(canremove(mid))
            l=mid+1;
        else
            h=mid;
    }
    printf("%i", h-1);
}
