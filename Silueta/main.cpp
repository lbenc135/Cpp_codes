#include <cstdio>
using namespace std;

#define INF 1000000000

int n, l, r, h;
char slika[1001][1001];
char rj[1001][1001];
bool visited[1001][1001];

void ispis(int lo, int hi, int v)
{
    for(int i=v;i>=0;i--)
    {
        for(int j=lo;j<hi;j++)
        {
            if(rj[j][i]==0) printf(".");
            else printf("%c", rj[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int lo=INF, hi=0, v=0;
    scanf("%i", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%i %i %i", &l, &r, &h);
        if(l<lo) lo=l;
        if(r>hi) hi=r;
        if(h>v) v=h;

        for(int j=1;j<=h;j++)
        {
            slika[l][j]='#';
            slika[r-1][j]='#';
        }
        for(int j=l;j<r;j++)
            slika[j][h]='#';
    }

    for(int i=lo;i<hi;i++)
        rj[i][0]='*';
    int x=lo, y=1, ops=0;
    while(!(x==hi && y==1))
    {
        if(slika[x][y]=='#') { rj[x][y]='#'; ops++;}
        visited[x][y]=true;
        if(slika[x][y+1]=='#' && !visited[x][y+1])
            y++;
        else if(slika[x+1][y]=='#' && !visited[x+1][y])
            x++;
        else if(slika[x][y-1]=='#' && !visited[x][y-1])
            y--;
        else x++;
    }
    for(int i=lo;i<hi;i++)
        if(rj[i][1]=='#') ops++;

    printf("%i\n", ops);
    ispis(lo, hi, v);
}
