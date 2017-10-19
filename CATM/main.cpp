#include <iostream>
#include <queue>
using namespace std;

void resetVisited();
void BFS(int x, int y, int p);

int n, m;
int polje[101][101][3];
bool visited[101][101];

struct stanje {
    int x, y, time;

    stanje(int x, int y, int time) {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

int main()
{
    int t;
    cin >> n >> m >> t;
    for(int c=0;c<t;c++) {
        int mx, my, c1x, c2x, c1y, c2y;
        cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
        resetVisited();
        BFS(--mx, --my, 0);
        resetVisited();
        BFS(--c1x, --c1y, 1);
        resetVisited();
        BFS(--c2x, --c2y, 2);

        bool canEscape = false;
        for(int i=0;i<n;i++)
            if(polje[i][0][0]<polje[i][0][1] && polje[i][0][0]<polje[i][0][2]) {
                canEscape = true;
                break;
            }
        for(int i=0;i<n;i++)
            if(polje[i][m-1][0]<polje[i][m-1][1] && polje[i][m-1][0]<polje[i][m-1][2] || canEscape){
                canEscape = true;
                break;
            }
        for(int i=0;i<m;i++)
            if(polje[0][i][0]<polje[0][i][1] && polje[0][i][0]<polje[0][i][2] || canEscape){
                canEscape = true;
                break;
            }
        for(int i=0;i<m;i++)
            if(polje[n-1][i][0]<polje[n-1][i][1] && polje[n-1][i][0]<polje[n-1][i][2] || canEscape){
                canEscape = true;
                break;
            }

        if(canEscape)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

void resetVisited()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j]=false;
}

void BFS(int x, int y, int p)
{
    queue<stanje> q;
    stanje s(x, y, 0);
    q.push(s);
    while(!q.empty()) {
        stanje t = q.front();
        q.pop();
        visited[t.x][t.y] = true;
        polje[t.x][t.y][p] = t.time;

        if(t.x+1<n && !visited[t.x+1][t.y]) {
            q.push(stanje(t.x+1, t.y, t.time+1));
            visited[t.x+1][t.y] = true;
        }
        if(t.x-1>=0 && !visited[t.x-1][t.y]) {
            q.push(stanje(t.x-1, t.y, t.time+1));
            visited[t.x-1][t.y] = true;
        }
        if(t.y+1<m && !visited[t.x][t.y+1]) {
            q.push(stanje(t.x, t.y+1, t.time+1));
            visited[t.x][t.y+1] = true;
        }
        if(t.y-1>=0 && !visited[t.x][t.y-1]) {
            q.push(stanje(t.x, t.y-1, t.time+1));
            visited[t.x][t.y-1] = true;
        }
    }
}
