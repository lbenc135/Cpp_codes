/*
ID: lbenc131
PROG: barn1
LANG: C++
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");

	int m, s, c;
	int stall[201];
	fscanf(fin, "%i %i %i", &m, &s, &c);
	for(int i=0;i<c;i++)
        fscanf(fin, "%i", &stall[i]);

    sort(stall, stall+c);
    int gap[201];
    for(int i=1;i<c;i++)
        gap[i]=stall[i]-stall[i-1];
	sort(gap+1, gap+c, greater<int>());

    if(m>c) m=c;
    int uk=stall[c-1]-stall[0]+1;
    for(int i=1;i<m;i++)
        uk-=gap[i]-1;

	fprintf(fout, "%i\n", uk);

    return 0;
}
