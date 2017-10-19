#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int r, s, t;
char polje[101][101];
bool visited[101][101];

struct coor{
    int x;
    int y;
};
struct stanje{
    int x;
    int y;
    int vrijeme;

    stanje(){}

    stanje(int v) {
        vrijeme=v;
    }
};

stanje BFS(struct stanje &, int ciljx, int ciljy);

int main()
{
    int ciljx, ciljy;
    scanf("%i", &t);
    stanje start(0);
    while(t--)
    {
        scanf("%i %i", &r, &s);
        for(int i=0;i<r;i++)
        {
            scanf("%s", &polje[i]);
            for(int j=0;j<s;j++)
            {
                if(polje[i][j]=='$') {start.x = i; start.y=j;}
                if(polje[i][j]=='#') {ciljx = i; ciljy=j;}
            }
        }

        stanje tr = BFS(start, ciljx, ciljy);
        printf("%i\n", tr.vrijeme);
        memset(visited, 0, sizeof(visited));
    }
}

stanje BFS(stanje &start, int ciljx, int ciljy)
{
    queue<stanje> q;
    stanje tr;
    q.push(start);
    while(!q.empty())
    {
        tr=q.front();
        if(tr.x==ciljx && tr.y==ciljy) return tr;
        visited[tr.x][tr.y]=true;
        q.pop();
        tr.vrijeme++;

        if(tr.x>0 && !visited[tr.x-1][tr.y] && polje[tr.x-1][tr.y]!='*') {q.push(tr);q.back().x--;}
        if(tr.x<r-1 && !visited[tr.x+1][tr.y] && polje[tr.x+1][tr.y]!='*') {q.push(tr);q.back().x++;}
        if(tr.y>0 && !visited[tr.x][tr.y-1] && polje[tr.x][tr.y-1]!='*') {q.push(tr);q.back().y--;}
        if(tr.y<s-1 && !visited[tr.x][tr.y+1] && polje[tr.x][tr.y+1]!='*') {q.push(tr);q.back().y++;}
    }
    return stanje(-1);
}
