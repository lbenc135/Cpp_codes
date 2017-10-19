#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

double gxcoor[100], gycoor[100];
double hxcoor[100], hycoor[100];

vector<int> vt[100];
int n, m, s, v;
int bio[100], par[100];

double calcTime(int x, int y, int x2, int y2)
{
    return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/v;
}

bool upari(int x)
{
    bio[x]=1;
    for(int i=0;i<vt[x].size();i++)
    {
        int rupa=vt[x][i];
        if(par[rupa]==-1 || !bio[par[rupa]] && upari(par[rupa]))
        {
            par[rupa]=x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m >> s >> v;
    for(int i=0;i<n;i++)
        cin >> gxcoor[i] >> gycoor[i];
    for(int i=0;i<m;i++)
        cin >> hxcoor[i] >> hycoor[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int sec=calcTime(gxcoor[i], gycoor[i], hxcoor[j], hycoor[j]);
            if(sec<=s) vt[i].push_back(j);
        }

    int rj=0;
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++)
    {
        memset(bio,0,sizeof(bio));
        rj+=upari(i);
    }
    cout << rj;
}
