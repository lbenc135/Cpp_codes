#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, niz[100];
int stanje[100];

int calc()
{
    int maks=0, j;
    for(int i=0;i<n;i++)
    {
        stanje[i]=10000000;
        for(j=0;stanje[j]<niz[i];j++)
            continue;
        stanje[j]=niz[i];
        maks=max(maks, j+1);
    }
    return maks;
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i", &niz[i]);

    printf("%i\n", calc());
}
