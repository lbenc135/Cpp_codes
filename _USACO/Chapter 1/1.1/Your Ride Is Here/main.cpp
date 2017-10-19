/*
ID: lbenc131
PROG: ride
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");

	char s1[7], s2[7];
	fscanf(fin, "%s %s", &s1, &s2);
	int len1=strlen(s1), len2=strlen(s2);

	int r1=1, r2=1;
	for(int i=0;i<len1;i++)
        r1*=s1[i]-'A'+1;
    r1%=47;

    for(int i=0;i<len2;i++)
        r2*=s2[i]-'A'+1;
    r2%=47;

    if(r1==r2) fprintf(fout, "GO\n");
    else fprintf(fout, "STAY\n");
    return 0;
}
