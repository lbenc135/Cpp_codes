/*
ID: lbenc131
PROG: ariprog
LANG: C++
*/
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

bool num[3250001];
pii v[10001];
int it=0;

int main() {
    FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");

	int n, m;
	fscanf(fin, "%i %i", &n, &m);

	for(int i=0;i<=m;i++)
        for(int j=i;j<=m;j++)
            num[i*i+j*j]=1;

    for(int i=0;i<125000;i++)
    {
        if(!num[i]) continue;
        for(int j=1;j<=(125000-i)/(n-1);j++)
        {
            bool can=true;
            for(int k=1;k<n;k++)
                if(!num[i+k*j]) { can=false; break; }
            if(can) v[it++]=pii(j, i);
        }
    }

    if(it==0) fprintf(fout, "NONE\n");
    else
    {
        sort(v, v+it);
        for(int i=0;i<it;i++)
            fprintf(fout, "%i %i\n", v[i].second, v[i].first);
    }

    return 0;
}
