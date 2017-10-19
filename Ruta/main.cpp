#include <cstdio>
#include <string>
using namespace std;

struct adresa {
    int n[4];
    string getBin()
    {
        int t[4];
        string s;
        for(int i=0;i<4;i++)
        {
            t[i]=n[i];
            int add2=8;
            while(t[i]>0)
            {
                s+=t[i]%2+'0';
                t[i]/=2;
                add2--;
            }
            s+=string(add2, '0');
        }
        return s;
    }
};

int main()
{
    int n, q;
    scanf("%i %i", &n, &q);
    adresa d[101], m[101];
    int s[101];
    adresa x;
    for(int i=0;i<n;i++)
        scanf("%i.%i.%i.%i %i.%i.%i.%i %i", &d[i].n[0], &d[i].n[1], &d[i].n[2], &d[i].n[3], &m[i].n[0], &m[i].n[1], &m[i].n[2], &m[i].n[3], &s[i]);
    for(int i=0;i<q;i++)
    {
        scanf("%i.%i.%i.%i", &x.n[0], &x.n[1], &x.n[2], &x.n[3]);
        string xs=x.getBin();
        for(int j=0;j<n;j++)
        {
            string ds=d[j].getBin();
            string ms=m[j].getBin();
            bool can=true;
            for(int k=0;k<32;k++)
                if(ms[k]=='1' && ds[k]!=xs[k]) {can=0; break;}
            if(can)
            {
                printf("%i\n", s[j]);
                break;
            }
        }
    }
    return 0;
}
