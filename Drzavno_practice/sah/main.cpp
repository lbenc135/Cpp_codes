#include <cstdio>
using namespace std;

int n, m;
int ax, ay, bx, by;
unsigned long long stanje[51][51][51];
int help1[]={1,-1,0,0,1,1,-1,-1,2,2,1,1,-1,-1,-2,-2};
int help2[]={0,0,1,-1,1,-1,-1,1,1,-1,2,-2,2,-2,1,-1};

bool goodCoor(int x, int y)
{
    if(x>=0  && x<n && y>=0 && y<n) return true;
    return false;
}

void init()
{
    for(int i=0;i<16;i++)
        if(goodCoor(ax+help1[i], ay+help2[i]))
            stanje[ax+help1[i]][ay+help2[i]][1]=1;
}

void printSt()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%i ", stanje[i][j][1]);
        printf("\n");
    }
    printf("\n");
}

void calc()
{
    init();

    for(int k=2;k<=m;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int l=0;l<16;l++)
                    if(goodCoor(i+help1[l], j+help2[l]))
                        stanje[i][j][k]+=stanje[i+help1[l]][j+help2[l]][k-1];
            }
        }
    }
}

int main()
{
    scanf("%i %i", &n, &m);
    scanf("%i %i %i %i", &ax, &ay, &bx, &by);
    //ax--; ay--; bx--; by--;

    calc();
    printf("%lli\n", stanje[bx][by][m]);
}
