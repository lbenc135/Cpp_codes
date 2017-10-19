#include <cstdio>
#include <cstring>
using namespace std;

char a[10001], b[10001];
int rez[10000], k, rj[200000000];

void add(int off)
{
    int c=0;
    for(int i=k;i>=0;i--)
    {
        rj[i+off]+=rez[i]+c;
        c=rj[i+off]/10;
        rj[i+off]%=10;
    }
}

void multiply(int la, int lb)
{
    int carry=0, k1;
    for(int i=0;i<lb;i++)
    {
        memset(rez, 0, sizeof(rez));
        k1=k;
        for(int j=la-1;j>=0;j--)
        {
            rez[k1]=a[j]*b[i]+carry;
            carry=rez[k1]/10;
            rez[k1]%=10;
            k1--;
        }
        while(carry)
        {
            rez[k1]=carry%10;
            carry/=10;
            k1--;
        }
        add(i);
    }
    k+=lb-1;
}

int main()
{
    int n, lena, lenb;
    scanf("%i", &n);
    for(int i=0;i<n;i++)
    {
        memset(rj, 0, sizeof(rj));
        scanf("%s %s", &a, &b);
        lena = strlen(a);
        lenb = strlen(b);
        k=lena+lenb;
        for(int i=0;i<lena;i++) a[i]-='0';
        for(int i=0;i<lenb;i++) b[i]-='0';

        multiply(lena, lenb);
        bool had=false;
        for(int i=0;i<=k;i++)
        {
            if(!had && rj[i]==0) continue;
            had=1;
            printf("%i", rj[i]);
        }
        printf("\n");
    }
}
