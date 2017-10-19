/*
ID: lbenc131
PROG: sort3
LANG: C++
*/
#include <cstdio>
using namespace std;

int n, swaps;
int seq[1001];
int num[4];

int findN(int a, int si)
{
    for(int i=si;i<n;i++)
        if(seq[i]==a) return i;
    return 0;
}

void exc(int i, int j)
{
    seq[i]^=seq[j];
    seq[j]^=seq[i];
    seq[i]^=seq[j];
    swaps++;
}

int main() {
    FILE *fin  = fopen ("sort3.in", "r");
    FILE *fout = fopen ("sort3.out", "w");

	fscanf(fin, "%i", &n);
	for(int i=0;i<n;i++)
    {
        fscanf(fin, "%i", &seq[i]);
        num[seq[i]]++;
    }

    for(int i=0;i<num[1]+num[2];i++)
    {
        if(i<num[1] && seq[i]!=1)
            exc(i, findN(1, seq[i]==2?num[1]:num[1]+num[2]));
        else if(i>=num[1] && seq[i]!=2)
            exc(i, findN(2, num[1]+num[2]));
    }

    fprintf(fout, "%i\n", swaps);

    return 0;
}
