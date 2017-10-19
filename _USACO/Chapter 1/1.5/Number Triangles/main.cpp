/*
ID: lbenc131
PROG: numtri
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int pir[1001][1001];
int stanje[1001][1001];

int main()
{
    FILE *fin  = fopen ("numtri.in", "r");
    FILE *fout = fopen ("numtri.out", "w");

    int n;
    fscanf(fin, "%i", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            fscanf(fin, "%i", &pir[i][j]);

    int maks=0;
    stanje[0][0]=pir[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) stanje[i][j]=stanje[i-1][j]+pir[i][j];
            else stanje[i][j]=max(stanje[i-1][j], stanje[i-1][j-1])+pir[i][j];
            if(i==n-1 && stanje[i][j]>maks) maks=stanje[i][j];
        }
    }
    fprintf(fout, "%i\n", maks);
}
