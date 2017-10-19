/*
ID: lbenc131
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

char l[]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int numl[7];

void turn2Rom(int a, int d)
{
    memset(numl, 0, sizeof(numl));
    switch(a)
    {
    case 1:
        numl[0+2*d]=1;
        break;
    case 2:
        numl[0+2*d]=2;
        break;
    case 3:
        numl[0+2*d]=3;
        break;
    case 4:
    case 6:
        numl[0+2*d]=1;
        numl[1+2*d]=1;
        break;
    case 5:
        numl[1+2*d]=1;
        break;
    case 7:
        numl[0+2*d]=2;
        numl[1+2*d]=1;
        break;
    case 8:
        numl[0+2*d]=3;
        numl[1+2*d]=1;
        break;
    case 9:
        numl[0+2*d]=1;
        numl[2+2*d]=1;
        break;
    default:
        break;
    }
}

int main() {
    FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");

	int n, temp;
	fscanf(fin, "%i", &n);

	int nl[7]={0};
	for(int i=1;i<=n;i++)
    {
        temp=i;
        for(int j=0;temp>0;j++)
        {
            turn2Rom(temp%10, j);
            temp/=10;
            for(int k=0;k<7;k++)
                nl[k]+=numl[k];
        }
    }
	for(int i=0;i<7;i++)
    {
        if(nl[i]==0) break;
        fprintf(fout, "%c %i\n", l[i], nl[i]);
    }

    return 0;
}
