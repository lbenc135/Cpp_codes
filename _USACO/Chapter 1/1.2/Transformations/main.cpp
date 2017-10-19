/*
ID: lbenc131
PROG: transform
LANG: C++
*/
#include <cstdio>
using namespace std;

int n;
char polje[11][11], polje2[11][11], temp[11][11];

bool rot90(bool t=false)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(t) polje[n-1-j][i]=temp[n-1-j][i];
            if(polje2[i][j]!=polje[n-1-j][i])
                return false;
        }
    return true;
}

bool rot180(bool t=false)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(t) polje[n-1-i][n-1-j]=temp[n-1-i][n-1-j];
            if(polje2[i][j]!=polje[n-1-i][n-1-j])
                return false;
        }
    return true;
}

bool rot270(bool t=false)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(t) polje[j][n-1-i]=temp[j][n-1-i];
            if(polje2[i][j]!=polje[j][n-1-i])
                return false;
        }
    return true;
}

bool refl()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(polje2[i][j]!=polje[i][n-1-j])
                return false;
        }
    return true;
}

bool comb()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp[i][j]=polje[i][n-1-j];
    if(rot90(1) || rot180(1) || rot270(1)) return true;
    return false;
}

bool nochg()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(polje2[i][j]!=polje[i][j])
                return false;
        }
    return true;
}

int main() {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");

	fscanf(fin, "%i", &n);
	for(int i=0;i<n;i++)
        fscanf(fin, "%s", polje[i]);
	for(int i=0;i<n;i++)
        fscanf(fin, "%s", polje2[i]);

    if(rot90()) fprintf(fout, "1\n");
    else if(rot180()) fprintf(fout, "2\n");
    else if(rot270()) fprintf(fout, "3\n");
    else if(refl()) fprintf(fout, "4\n");
    else if(comb()) fprintf(fout, "5\n");
    else if(nochg()) fprintf(fout, "6\n");
    else fprintf(fout, "7\n");

    return 0;
}
