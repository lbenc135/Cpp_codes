#include <cstdio>
#include <cstring>
using namespace std;

int dobit[50][50], polje[50][50];
int n;

int calcdobit(int x1, int y1, int x2, int y2)
{
    int rez=dobit[x2][y2];
    if(y1-1>=0) rez-=dobit[x2][y1-1];
    if(x1-1>=0) rez-=dobit[x1-1][y2];
    if(x1-1>=0 && y1-1>=0) rez+=dobit[x1-1][y1-1];
    return rez;
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%i", &polje[i][j]);

    dobit[0][0]=polje[0][0];
    for(int i=1;i<n;i++)
        dobit[0][i]=polje[0][i]+dobit[0][i-1];
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
        {
            dobit[i][j]=dobit[i-1][j]+polje[i][j];
            if(j>0) dobit[i][j]+=dobit[i][j-1]-dobit[i-1][j-1];
        }

    long long rez=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            int temp[500000]={0};
            for(int k=0;k<=i;k++)
                for(int l=0;l<=j;l++)
                    temp[calcdobit(i-k, j-l, i, j)+250000]++;

            for(int m=i+1;m<n;m++)
                for(int o=j+1;o<n;o++)
                    rez+=temp[calcdobit(i+1, j+1, m, o)+250000];

            memset(temp, 0, sizeof(temp));
            for(int k=0;k<=i;k++)
                for(int l=1;j+l<n;l++)
                {
                    int d=calcdobit(i-k, j+1, i, j+l);
                    temp[d+250000]++;
                }


            for(int m=i+1;m<n;m++)
                for(int o=j;o>=0;o--)
                    rez+=temp[calcdobit(i+1, o, m, j)+250000];
        }
    }

    printf("%lli", rez);
}
