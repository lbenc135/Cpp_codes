#include <iostream>
#include <queue>
using namespace std;

bool visited[100][100];
struct coor{
    int x;
    int y;
};

struct stanje{
    int x;
    int y;
    int vrijeme=0;
    coor put[1000];
};

stanje BFS(struct stanje &, int ciljx, int ciljy);
int r,s;
char polje[100][100];

int main()
{
    int ciljx, ciljy;
    cin >> r >> s;

    stanje start;

    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
        {
            cin >> polje[i][j];
            if(polje[i][j]=='M') {start.x = i; start.y=j;}
            if(polje[i][j]=='I') {ciljx = i; ciljy=j;}
        }

    stanje tr = BFS(start, ciljx, ciljy);
    cout << tr.vrijeme << endl;


    for(int i=0;i<1000;i++)
        polje[tr.put[i].x][tr.put[i].y]='P';
    polje[ciljx][ciljy]='I';
    polje[start.x][start.y]='M';

    cout << endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
            cout << polje[i][j];
        cout << endl;
    }
}

stanje BFS(stanje &start, int ciljx, int ciljy)
{
    queue<stanje> q;
    stanje tr;
    for(int i=0;i<1000;i++)
    {
        start.put[i].x=99;
        start.put[i].y=99;
    }
    q.push(start);
    while(!q.empty())
    {
        tr=q.front();
        if(tr.x==ciljx && tr.y==ciljy) return tr;
        visited[tr.x][tr.y]=true;
        q.pop();
        tr.put[tr.vrijeme].x=tr.x;
        tr.put[tr.vrijeme].y=tr.y;
        tr.vrijeme++;

        if(visited[tr.x-1][tr.y]==false && polje[tr.x-1][tr.y]!='#' && tr.x>0) {q.push(tr);q.back().x--;}
        if(visited[tr.x+1][tr.y]==false && polje[tr.x+1][tr.y]!='#' && tr.x<s) {q.push(tr);q.back().x++;}
        if(visited[tr.x][tr.y-1]==false && polje[tr.x][tr.y-1]!='#' && tr.y>0) {q.push(tr);q.back().y--;}
        if(visited[tr.x][tr.y+1]==false && polje[tr.x][tr.y+1]!='#' && tr.y<r) {q.push(tr);q.back().y++;}

        if(visited[tr.x-1][tr.y-1]==false && polje[tr.x-1][tr.y-1]!='#' && tr.x>0 && tr.y>0) {q.push(tr);q.back().x--;q.back().y--;}
        if(visited[tr.x+1][tr.y+1]==false && polje[tr.x+1][tr.y+1]!='#' && tr.x<s && tr.y<r) {q.push(tr);q.back().x++;q.back().y++;}
        if(visited[tr.x+1][tr.y-1]==false && polje[tr.x+1][tr.y-1]!='#' && tr.y>0 && tr.x<s) {q.push(tr);q.back().y--;q.back().x++;}
        if(visited[tr.x-1][tr.y+1]==false && polje[tr.x-1][tr.y+1]!='#' && tr.y<r && tr.x>0) {q.push(tr);q.back().y++;q.back().x--;}
    }
}
