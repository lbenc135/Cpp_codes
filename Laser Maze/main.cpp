#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int visited[101][101];
char maze[101][101];
int lasers, laser[100001][2];
int sx, sy, gx, gy;
int m, n;

struct stanje{
    int x;
    int y;
    int vrijeme;
    stanje() {}
    stanje(int tx, int ty, int t=0)
    {
        x=tx; y=ty; vrijeme=t;
    }
};

void turnLasers(int times)
{
    times%=4;
    for(int j=0;j<times;j++)
        for(int i=0;i<lasers;i++)
        {
            int x=laser[i][0], y=laser[i][1];
            if(maze[x][y]=='<') maze[x][y]='^';
            else if(maze[x][y]=='^') maze[x][y]='>';
            else if(maze[x][y]=='>') maze[x][y]='v';
            else if(maze[x][y]=='v') maze[x][y]='<';
        }
}

void returnLasers(int times)
{
    times%=4;
    for(int j=0;j<times;j++)
        for(int i=0;i<lasers;i++)
        {
            int x=laser[i][0], y=laser[i][1];
            if(maze[x][y]=='<') maze[x][y]='v';
            else if(maze[x][y]=='^') maze[x][y]='<';
            else if(maze[x][y]=='>') maze[x][y]='^';
            else if(maze[x][y]=='v') maze[x][y]='>';
        }
}

bool isAlive(int mx, int my)
{
    for(int i=0;i<lasers;i++)
    {
        int x=laser[i][0], y=laser[i][1];
        if(maze[x][y]=='<' && mx==x && my<y) return false;
        else if(maze[x][y]=='^' && my==y && mx<x) return false;
        else if(maze[x][y]=='>' && mx==x && my>y) return false;
        else if(maze[x][y]=='v' && my==y && mx>x) return false;
    }
    return true;
}

bool isFree(int x, int y)
{
    if((maze[x][y]=='.' || maze[x][y]=='G' || maze[x][y]=='S') && x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

int BFS(stanje st)
{
    queue<stanje> q;
    q.push(st);

    while(!q.empty())
    {
        stanje s=q.front();
        q.pop();

        if(s.x==gx && s.y==gy) return s.vrijeme;

        turnLasers(s.vrijeme+1);
        visited[s.x][s.y]++;

        if(isFree(s.x+1, s.y) && isAlive(s.x+1, s.y) && visited[s.x+1][s.y]<20)
            q.push(stanje(s.x+1, s.y, s.vrijeme+1));
        if(isFree(s.x, s.y+1) && isAlive(s.x, s.y+1) && visited[s.x][s.y+1]<20)
            q.push(stanje(s.x, s.y+1, s.vrijeme+1));
        if(isFree(s.x-1, s.y) && isAlive(s.x-1, s.y) && visited[s.x-1][s.y]<20)
            q.push(stanje(s.x-1, s.y, s.vrijeme+1));
        if(isFree(s.x, s.y-1) && isAlive(s.x, s.y-1) && visited[s.x][s.y-1]<20)
            q.push(stanje(s.x, s.y-1, s.vrijeme+1));

        returnLasers(s.vrijeme+1);
    }

    return -1;
}

int main()
{
    int t;
    scanf("%i", &t);
    int sol[101];
    for(int i=0;i<t;i++)
    {
        scanf("%i %i", &m, &n);
        lasers=0;
        memset(visited, 0, sizeof(visited));
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++)
            {
                 scanf(" %c", &maze[j][k]);
                 if(maze[j][k]=='S') {sx=j; sy=k;}
                 else if(maze[j][k]=='G') {gx=j; gy=k;}
                 else if(maze[j][k]=='<' || maze[j][k]=='>' || maze[j][k]=='v' || maze[j][k]=='^')
                 {  laser[lasers][0]=j; laser[lasers][1]=k; lasers++; }
            }

        sol[i]=BFS(stanje(sx, sy));
    }
    for(int i=0;i<t;i++)
        if(sol[i]!=-1) printf("Case #%i: %i\n", i+1, sol[i]);
        else printf("Case #%i: impossible\n", i+1);
}
