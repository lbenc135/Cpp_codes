/*
ID: lbenc131
PROG: gift1
LANG: C++
*/
#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

char names[10][15];

int main() {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");

	int n;
	char a[15], b[15];
	fscanf(fin, "%i", &n);
	for(int i=0;i<n;i++)
    {
        fscanf(fin, "%s", &names[i]);
        m[string(names[i])]=0;
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fin, "%s", &a);
        int money, p;
        fscanf(fin, "%i %i", &money, &p);
        if(p==0) continue;
        m[string(a)]-=money-money%p;
        money/=p;
        for(int j=0;j<p;j++)
        {
            fscanf(fin, "%s", &b);
            m[string(b)]+=money;
        }
    }
	for(int i=0;i<n;i++)
        fprintf(fout, "%s %i\n", names[i], m[names[i]]);
    return 0;
}
