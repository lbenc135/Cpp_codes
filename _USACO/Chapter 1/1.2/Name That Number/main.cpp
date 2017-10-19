/*
ID: lbenc131
PROG: namenum
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int num(char c)
{
    if(c>='A' && c<='C') return 2;
    if(c>='D' && c<='F') return 3;
    if(c>='G' && c<='I') return 4;
    if(c>='J' && c<='L') return 5;
    if(c>='M' && c<='O') return 6;
    if(c>='P' && c<='S' && c!='Q') return 7;
    if(c>='T' && c<='V') return 8;
    if(c>='W' && c<='Y') return 9;
    return 1;
}

int main() {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
	FILE *dict = fopen ("dict.txt", "r");

	long long serial;
	fscanf(fin, "%lli", &serial);

	long long temp;
	char name[13];
	bool moze, none=true;
	while(fscanf(dict, "%s", &name)>0)
    {
        moze=true;
        temp=serial;
        int len=strlen(name);
        for(int i=len-1;i>=0;i--)
        {
            if(num(name[i])!=temp%10) { moze=false; break; }
            temp/=10;
        }
        if(moze && temp==0) { none=false; fprintf(fout, "%s\n", name); }
    }
	if(none) fprintf(fout, "NONE\n");

    return 0;
}
