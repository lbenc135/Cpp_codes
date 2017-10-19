#include <iostream>
#include <queue>
using namespace std;

void drawLaserx(int y1,int y2,int x);
void drawLasery(int x1,int x2,int y);
void drawPolje();
void push(int,int);
bool blank();

int n,m;
bool visited[100][100]={false};
char polje[30][30];
struct coor {int x;int y;};
struct stanje {int x;int y;int vrijeme = 0;};
int vrijeme=-1;
bool possible=0;

int BFS(struct stanje &,int,int);

int main()
{
    stanje start;
    int ciljx, ciljy;
    coor *laser = new coor[30];
    int lasera=0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> polje[i][j];
            if(polje[i][j]=='U') {start.x=i;start.y=j;}
            if(polje[i][j]=='S') {ciljx=i;ciljy=j;}
            if(polje[i][j]=='L') {laser[lasera].x=i;laser[lasera].y=j;lasera++;}
        }
    }
    for(int i=0;i<lasera;i++)
    {
        for(int j=i;j<lasera;j++)
        {
            if(i!=j && laser[i].x==laser[j].x)
                drawLaserx(laser[i].y,laser[j].y, laser[j].x);
            if(i!=j && laser[i].y==laser[j].y)
                drawLasery(laser[i].x,laser[j].x, laser[j].y);
        }
    }

    cout << BFS(start, ciljx, ciljy)+1;
}

void drawLaserx(int y1,int y2,int x)
{
    for(int i=y1;i<y2;i++)
        polje[x][i]='L';
}

void drawLasery(int x1,int x2,int y)
{
    for(int i=x1;i<x2;i++)
        polje[i][y]='L';
}


int BFS(stanje &start, int ciljx, int ciljy)
{
    queue<stanje> q;
    q.push(start);
    stanje tr;

    while(!q.empty())
    {
        tr=q.front();
        visited[tr.x][tr.y]=true;
        if(tr.x==ciljx && tr.y==ciljy) return tr.vrijeme;
        if(visited[tr.x-1][tr.y]==false && tr.x>0 && polje[tr.x-1][tr.y]!='#' && polje[tr.x-1][tr.y]!='L') {q.push(tr);q.back().x-=1;q.back().vrijeme++;}
        if(visited[tr.x][tr.y-1]==false && tr.y>0 && polje[tr.x][tr.y-1]!='#' && polje[tr.x][tr.y-1]!='L') {q.push(tr);q.back().y-=1;q.back().vrijeme++;}
        if(visited[tr.x+1][tr.y]==false && tr.x<n-1 && polje[tr.x+1][tr.y]!='#' && polje[tr.x+1][tr.y]!='L') {q.push(tr);q.back().x+=1;q.back().vrijeme++;}
        if(visited[tr.x][tr.y+1]==false && tr.y<m-1 && polje[tr.x][tr.y+1]!='#' && polje[tr.x][tr.y+1]!='L') {q.push(tr);q.back().y+=1;q.back().vrijeme++;}
        q.pop();
    }
    return -2;
}
