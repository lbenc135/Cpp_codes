#include <cstdio>
using namespace std;

#define MAXN 100000

int gd[10000][10000];

int gcd(int a, int b) {
    if(a<10000 && b<10000 && gd[a][b]!=0)
        return gd[a][b];
    int rez = b==0?a:gcd(b, a%b);
    gd[a][b] = gd[b][a] = rez;
    return rez;
}

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        int n;
        scanf("%i", &n);
        int cn = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                {
                    if(gcd(i, j)==1 && gcd(i, k)==1 && gcd(j, k)==1)
                    {
                        cn++;
                    }
                }

        printf("%i\n", cn);
    }
}
