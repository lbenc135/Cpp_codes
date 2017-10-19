/*
ID: lbenc131
PROG: friday
LANG: C++
*/
#include <cstdio>
using namespace std;

int f[7];

bool is_prestupna(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

int main() {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");

	int n;
	fscanf(fin, "%i", &n);
	bool prestupna;
	int dan=1;
	for(int i=0;i<n;i++)
    {
        prestupna=is_prestupna(1900+i);
        for(int j=0;j<12;j++)
        {
            int d;
            if(j==0 || j==2 || j==4 || j==6 || j==7 || j==9 ||j==11) d=31;
            else if(j==1 && prestupna) d=29;
            else if(j==1) d=28;
            else d=30;

            for(int k=0;k<d;k++)
            {
                if(k==13) f[dan]++;

                dan++;
                if(dan>=7) dan%=7;
            }
        }
    }
    for(int i=0;i<7;i++)
        if(i==6) fprintf(fout, "%i\n", f[i]);
        else fprintf(fout, "%i ", f[i]);

    return 0;
}
