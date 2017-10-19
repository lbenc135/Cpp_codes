/*
ID: lbenc131
PROG: holstein
LANG: C++
*/
#include <cstdio>
using namespace std;

int main() {
    FILE *fin  = fopen ("holstein.in", "r");
    FILE *fout = fopen ("holstein.out", "w");

	int v, g;
	int vitamins[26], feeds[16][26];
	fscanf(fin, "%i", &v);
	for(int i=0;i<v;i++)
        fscanf(fin, "%i", &vitamins[i]);
    fscanf(fin, "%i", &g);
	for(int i=0;i<g;i++)
        for(int j=0;j<v;j++)
            fscanf(fin, "%i", &feeds[i][j]);

    int bm=0, mini=10000, temp, minibm;
    while(bm<(1<<g))
    {
        int tv[26]={0};
        temp=0;
        for(int i=0;i<g;i++)
            if(bm&(1<<i))
            {
                temp++;
                for(int j=0;j<v;j++)
                    tv[j]+=feeds[i][j];
            }
        bool can=true;
        for(int i=0;i<v;i++)
            if(tv[i]<vitamins[i]) { can=0; break; }
        if(can && temp<mini)
        {
            mini=temp;
            minibm=bm;
        }
        bm++;
    }

    fprintf(fout, "%i", mini);
    for(int i=0;i<g;i++)
        if(minibm&(1<<i)) fprintf(fout, " %i", i+1);
    fprintf(fout, "\n");

    return 0;
}
