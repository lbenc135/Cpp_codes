#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    int boja[m], h=0;
    for(int i=0;i<m;i++)
    {
        scanf("%i", &boja[i]);
        h+=boja[i];
    }

    int l=0, mid;
    while(l<h)
    {
        mid=(l+h)/2;
        int d=0;
        for(int i=0;i<m;i++)
            d+=(boja[i]+mid-1)/mid;
        if(d>n)
            l=mid+1;
        else
            h=mid;
    }
    printf("%i", l);
}
