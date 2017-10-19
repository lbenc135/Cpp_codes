/*
ID: lbenc131
PROG: dualpal
LANG: C++
*/
#include <cstdio>
#include <string>
using namespace std;

bool isPalin(string n)
{
    for(int i=0;i<n.length();i++)
    {
        if(n[i]!=n[n.length()-1-i]) return false;
    }
    return true;
}

string NumtoBase(int n, int b)
{
    string num;
    int it=0;
    while(n>0)
    {
        int r=n%b;
        num.insert(num.begin(), r+'0');

        n/=b;
        it++;
    }
    return num;
}

int main() {
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");

	int n, s;
	fscanf(fin, "%i %i", &n, &s);

	for(int i=s+1;n>0;i++)
    {
        int p=0;
        for(int j=2;j<=10;j++)
            if(isPalin(NumtoBase(i, j))) p++;
        if(p>=2) { fprintf(fout, "%i\n", i); n--; }
    }

    return 0;
}
