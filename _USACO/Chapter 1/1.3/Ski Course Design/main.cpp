/*
ID: lbenc131
PROG: skidesign
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

int has[101];

int sqr(int a) { return a*a; }

int main() {
    FILE *fin  = fopen ("skidesign.in", "r");
    FILE *fout = fopen ("skidesign.out", "w");

	int n, th, it=0;
	fscanf(fin, "%i", &n);
	pii h[1001];
	for(int i=0;i<n;i++)
    {
        fscanf(fin, "%i", &th);
        if(has[th]) h[has[th]-1].second++;
        else
        {
            h[it].first=th;
            h[it].second=1;
            it++;
            has[th]=it;
        }
    }
    sort(h, h+it);

    long long cost=100000000000000L;
    int lo=0, hi=17;
	while(hi<=100)
    {
        long long tempc=0;
        for(int i=0;i<it;i++)
            if(h[i].first<lo) tempc+=sqr(lo-h[i].first)*h[i].second;
            else if(h[i].first>hi) tempc+=sqr(h[i].first-hi)*h[i].second;

        if(tempc<cost) cost=tempc;
        lo++; hi++;
    }

    fprintf(fout, "%lli\n", cost);

    return 0;
}
