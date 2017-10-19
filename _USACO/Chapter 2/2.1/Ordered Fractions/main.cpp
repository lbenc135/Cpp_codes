/*
ID: lbenc131
PROG: frac1
LANG: C++
*/
#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

vector<pii > frac;

int gcd(int a, int b) { return b==0?a:gcd(b, a%b); }

bool comp(pii a, pii b) { return (float)a.first/a.second<(float)b.first/b.second; }

int main() {
    FILE *fin  = fopen ("frac1.in", "r");
    FILE *fout = fopen ("frac1.out", "w");

	int n;
	fscanf(fin, "%i", &n);

    frac.push_back(pii(0, 1));
    frac.push_back(pii(1, 1));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(gcd(i, j)==1) frac.push_back(pii(i, j));

    sort(frac.begin(), frac.end(), comp);

    for(int i=0;i<frac.size();i++)
        fprintf(fout, "%i/%i\n", frac[i].first, frac[i].second);

    return 0;
}
