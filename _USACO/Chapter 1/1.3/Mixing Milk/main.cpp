/*
ID: lbenc131
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");

	int n, m;
	fscanf(fin, "%i %i", &n, &m);
	pair<int,int> farm[5001];
	for(int i=0;i<m;i++)
        fscanf(fin, "%i %i", &farm[i].first, &farm[i].second);
	sort(farm, farm+m);

	int uk=0;
	for(int i=0;i<m && n>0;i++)
    {
        if(farm[i].second<=n)
        {
            n-=farm[i].second;
            uk+=farm[i].first*farm[i].second;
        }
        else
        {
            uk+=farm[i].first*n;
            n=0;
        }
    }
	fprintf(fout, "%i\n", uk);

    return 0;
}
