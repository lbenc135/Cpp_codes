#include <cstdio>
using namespace std;

int ul[100], iz[100];

int main()
{
    int t, n, maks, tr, miz;
    scanf("%d", &t);
    for(int a=0;a<t;a++)
    {
        maks=0; tr=0; miz=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d", &ul[i], &iz[i]);
            if(iz[i]>miz) miz=iz[i];
        }

        for(int i=1;i<=miz;i++)
        {
            tr=0;
            for(int j=0;j<n;j++)
                if(i>=ul[j] && i<=iz[j]) tr++;
            if(tr>maks) maks=tr;
        }
        printf("%d\n", maks);
    }
}
