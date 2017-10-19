/*
ID: lbenc131
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

#define MAXT 1000001

int t[MAXT];

int main() {
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");

	int n;
	int a, b, bg=MAXT, ed=0;
	fscanf(fin, "%i", &n);
	for(int i=0;i<n;i++)
    {
        fscanf(fin, "%i %i", &a, &b);
        t[a]++;
        t[b]--;
        if(a<bg) bg=a;
        if(b>ed) ed=b;
    }

    int c=0, tmp1=0, tmp2=0, lone=0, lno=0;
    for(int i=bg;i<ed;i++)
    {
        c+=t[i];
        if(c)
        {
            tmp1++;
            tmp2=0;
        }
        else
        {
            tmp1=0;
            tmp2++;
        }
        if(tmp1>lone) lone=tmp1;
        if(tmp2>lno) lno=tmp2;
    }

	fprintf(fout, "%i %i\n", lone, lno);
    return 0;
}
