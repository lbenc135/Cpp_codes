/*
ID: lbenc131
PROG: castle
LANG: C++
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int castle[51][51];
bool visited[51][51];
vector<int> rooms;
int n, m;

int DFS(int x, int y)
{
    if(visited[x][y]) return 0;
    visited[x][y]=1;
    int sz=1;

    if(!(1&castle[x][y]) && !visited[x][y-1])
        sz+=DFS(x, y-1);
    if(!(2&castle[x][y]) && !visited[x-1][y])
        sz+=DFS(x-1, y);
    if(!(4&castle[x][y]) && !visited[x][y+1])
        sz+=DFS(x, y+1);
    if(!(8&castle[x][y]) && !visited[x+1][y])
        sz+=DFS(x+1, y);

    return sz;
}

int main()
{
    FILE *fin  = fopen ("castle.in", "r");
    FILE *fout = fopen ("castle.out", "w");

    fscanf(fin, "%i %i", &m, &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            fscanf(fin, "%i", &castle[i][j]);

    int s, maxs=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            s=DFS(i, j);
            if(s!=0) rooms.push_back(s);
            if(s>maxs) maxs=s;
        }
    }

    int tmaxs=maxs, ti=n-1, tj=0;
    char side='N';
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            memset(visited, 0, sizeof(visited));
            if(i>0 && (2&castle[i][j]))
            {
                castle[i][j]-=2;
                s=DFS(i, j);
                if(s>tmaxs) { tmaxs=s; ti=i; tj=j; side='N'; }
                castle[i][j]+=2;
            }
            if(j<m-1 && (4&castle[i][j]))
            {
                castle[i][j]-=4;
                s=DFS(i, j);
                if(s>tmaxs) { tmaxs=s; ti=i; tj=j; side='E'; }
                castle[i][j]+=4;
            }
        }
    }

    fprintf(fout, "%i\n%i\n%i\n%i %i %c\n", rooms.size(), maxs, tmaxs, ti+1, tj+1, side);
}
