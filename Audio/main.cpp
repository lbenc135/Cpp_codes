#include <cstdio>
using namespace std;

int lennum(int a)
{
    int len=0;
    while(a>0)
    {
        len++;
        a/=10;
    }
    return len;
}

int lpref(int a, int b)
{
    int len1=lennum(a), len2=lennum(b);
    if(len1!=len2) return 0;
    int rez=len1, it=len1;
    while(a>0)
    {
        if(a%10!=b%10) rez=it-1;
        it--;
        a/=10; b/=10;
    }
    return rez;
}

int tenP(int a)
{
    int t=1;
    for(int i=0;i<a;i++)
        t*=10;
    return t;
}

int main()
{
    int n, t[100001];
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i", &t[i]);

    int poc=-1, kraj;
    for(int i=0;i<=n;i++)
    {
        if(i>0 && i<n && t[i]==t[i-1]+1)
            kraj=i;
        else if(poc!=-1)
        {
            if(poc==kraj) printf("%i\n", t[poc]);
            else
            {
                int lp=lpref(t[poc], t[kraj]);
                if(lp==0)
                    printf("%i-%i\n", t[poc], t[kraj]);
                else
                    printf("%i-%i\n", t[poc], t[kraj]%tenP(lennum(t[kraj])-lp));
            }
            poc=kraj=i;
        }
        else
            poc=kraj=i;
    }
}
