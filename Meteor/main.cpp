#include <cstdio>
using namespace std;

char slika[3001][3001];

int main()
{
    int r, s;
    scanf("%i %i", &r, &s);
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            scanf(" %c", &slika[i][j]);

    int mins=10000000;
    for(int j=0;j<s;j++)
    {
        int vt=r;
        for(int i=r-1;i>=0;i--)
        {
            if(slika[i][j]=='X')
            {
                if(mins>vt-i) mins=vt-i;
                break;
            }
            else if(slika[i][j]=='#') vt=i;
        }
    }
    mins--;
    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<s;j++)
        {
            if(slika[i][j]=='X')
            {
                slika[i+mins][j]='X';
                slika[i][j]='.';
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
            printf("%c", slika[i][j]);
        printf("\n");
    }

}
