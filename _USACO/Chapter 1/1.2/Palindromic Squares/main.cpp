/*
ID: lbenc131
PROG: palsquare
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
        char c;
        if(r<10) c=r+'0';
        else c='A'+r-10;
        num.insert(num.begin(), c);

        n/=b;
        it++;
    }
    return num;
}

int main() {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");

	int b;
	fscanf(fin, "%i", &b);

	for(int i=1;i<=300;i++)
    {
        string ib=NumtoBase(i, b);
        string num=NumtoBase(i*i, b);
        if(isPalin(num)) fprintf(fout, "%s %s\n", ib.c_str(), num.c_str());
    }

    return 0;
}
