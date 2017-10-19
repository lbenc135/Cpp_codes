/*
ID: lbenc131
PROG: subset
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long long state[1000][40];

long long rek(int n, int k)
{
    if(n<0 || k<0) return 0;
    if(state[n][k]!=-1) return state[n][k];
    if(n==0 && k==0) return state[n][k]=1;
    return state[n][k] = rek(n, k-1) + rek(n-k, k-1);
}

int main() {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");

    memset(state, -1, sizeof(state));

	int n;
	fscanf(fin, "%i", &n);

	int m=n*(n+1)/2;
	if(m%2) fprintf(fout, "0\n");
	else fprintf(fout, "%lli\n", rek(m/2, n)/2);

    return 0;
}
