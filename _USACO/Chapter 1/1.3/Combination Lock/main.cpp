/*
ID: lbenc131
PROG: combo
LANG: C++
*/
#include <cstdio>
using namespace std;

int n, f1, f2, f3, m1, m2, m3;

int mod(int a)
{
    while(a<1) a+=n;
    if(a>=1 && a<=n) return a;
    return a%n;
}

int goodDig(int d1, int d2)
{
    if(d1==d2 || d1==mod(d2-1) || d1==mod(d2-2) || d1==mod(d2+1) || d1==mod(d2+2)) return true;
    return false;
}

bool isGood(int a, int b, int c)
{
    if(goodDig(a, f1) && goodDig(b, f2) && goodDig(c, f3)) return true;
    if(goodDig(a, m1) && goodDig(b, m2) && goodDig(c, m3)) return true;
    return false;
}

int main() {
    FILE *fin  = fopen ("combo.in", "r");
    FILE *fout = fopen ("combo.out", "w");

	fscanf(fin, "%i %i %i %i %i %i %i", &n, &f1, &f2, &f3, &m1, &m2, &m3);

	long long rez=0;
	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(isGood(i, j, k)) rez++;
	fprintf(fout, "%lli\n", rez);

    return 0;
}
