/*
ID: lbenc131
PROG: crypt1
LANG: C++
*/
#include <cstdio>
using namespace std;

int n, digs[10];
int f, s[2];

bool isInDigs(int a)
{
    for(int i=0;i<n;i++) if(digs[i]==a) return true;
    return false;
}

bool good()
{
    int p1=f*s[0], p2=f*s[1], rez=f*(10*s[0]+s[1]);

    if(p1>=1000 || p2>=1000) return false;
    while(p1>0) { if(!isInDigs(p1%10)) return false; p1/=10; }
    while(p2>0) { if(!isInDigs(p2%10)) return false; p2/=10; }
    while(rez>0) { if(!isInDigs(rez%10)) return false; rez/=10; }
    return true;
}

int main() {
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");


	fscanf(fin, "%i", &n);
	for(int i=0;i<n;i++)
        fscanf(fin, "%i", &digs[i]);

	long long rez=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                f=100*digs[i]+10*digs[j]+digs[k];
                for(int l=0;l<n;l++)
                {
                    s[0]=digs[l];
                    for(int m=0;m<n;m++)
                    {
                        s[1]=digs[m];
                        if(good()) rez++;
                    }
                }
            }
        }
    }

    fprintf(fout, "%lli\n", rez);
    return 0;
}
