#include <cstdio>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int r, k;
int t[27], x[27], y[27];
char polje[101][101];
int rasa[27][1000001];
pair<int, char> planet[101][101];

struct stanje {
    int kor;
    char ras;
    int x, y, px, py;
    stanje(){};
    stanje(int kor, char ras, int x, int y, int px, int py)
    {
        this->kor=kor; this->ras=ras; this->x=x; this->y=y; this->px=px; this->py=py;
    }

    bool operator<(const stanje& rhs) const
    {
        return kor>rhs.kor;
    }
};

void draw()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(polje[i][j]=='$' || planet[i][j].second==0)
                printf("%c", polje[i][j]);
            else
                printf("%c", planet[i][j].second);
        }
        printf("\n");
    }
    printf("\n");
}

bool isGood(int x, int y, char ras)
{
    if(polje[x][y]=='$' || x<0 || x>=n || y<0 || y>=m || planet[x][y].second==ras) return false;
    return true;
}

void BFS()
{
    priority_queue<stanje> q;

    for(int i=0;i<r;i++)
    {
        q.push(stanje(t[i], i+'a', x[i]-1, y[i]-1, x[i]-1, y[i]-1));
    }
    stanje tr;

    while(!q.empty())
    {
        tr=q.top();
        q.pop();

        if(rasa[tr.ras-'a'][tr.kor]==0) rasa[tr.ras-'a'][tr.kor]=rasa[tr.ras-'a'][tr.kor-1];
        if(tr.kor>k || polje[tr.px][tr.py]=='$' || (planet[tr.px][tr.py].second!=tr.ras && (tr.x!=tr.px || tr.y!=tr.py)) || planet[tr.x][tr.y].second==tr.ras) continue;

        bool conq=false;

        if(planet[tr.x][tr.y].second==0)
        {
            planet[tr.x][tr.y]=pair<int, char>(tr.kor, tr.ras);
            rasa[tr.ras-'a'][tr.kor]++;
            conq=1;
        }
        else if(planet[tr.x][tr.y].first<tr.kor) continue;
        else if(planet[tr.x][tr.y].first==tr.kor && planet[tr.x][tr.y].second!=tr.ras)
        {
            if(rasa[tr.ras-'a'][tr.kor-1]>rasa[planet[tr.x][tr.y].second-'a'][tr.kor-1])
            {
                rasa[planet[tr.x][tr.y].second-'a'][tr.kor]--;
                planet[tr.x][tr.y]=pair<int, char>(tr.kor, tr.ras);
                rasa[tr.ras-'a'][tr.kor]++;
                conq=1;
            }
            else if(rasa[tr.ras-'a'][tr.kor-1]==rasa[planet[tr.x][tr.y].second-'a'][tr.kor-1])
            {
                polje[tr.x][tr.y]='$';
                rasa[planet[tr.x][tr.y].second-'a'][tr.kor]--;
            }
        }

        if(conq)
        {
            if(isGood(tr.x+1, tr.y, tr.ras))
                q.push(stanje(tr.kor+1, tr.ras, tr.x+1, tr.y, tr.x, tr.y));
            if(isGood(tr.x-1, tr.y, tr.ras))
                q.push(stanje(tr.kor+1, tr.ras, tr.x-1, tr.y, tr.x, tr.y));
            if(isGood(tr.x, tr.y+1, tr.ras))
                q.push(stanje(tr.kor+1, tr.ras, tr.x, tr.y+1, tr.x, tr.y));
            if(isGood(tr.x, tr.y-1, tr.ras))
                q.push(stanje(tr.kor+1, tr.ras, tr.x, tr.y-1, tr.x, tr.y));
        }
    }
}

int main()
{
    scanf("%i %i %i %i", &n, &m, &r, &k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %c", &polje[i][j]);

    for(int i=0;i<r;i++)
        scanf("%i %i %i", &t[i], &x[i], &y[i]);

    BFS();

    draw();

    return 0;
}
