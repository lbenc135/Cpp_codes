#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> vt[100];
int bio[100], par[100];

int n, m;
int bobx[100], boby[100];
int dogx[100], dogy[100];

double calcdist(int x, int y, int x2, int y2)
{
    return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
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
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> bobx[i] >> boby[i];
    for(int i=0;i<m;i++)
        cin >> dogx[i] >> dogy[i];

    for(int i=0;i<n-1;i++)
    {
        double dist0=calcdist(bobx[i], boby[i], bobx[i+1], boby[i+1])*2;
        for(int j=0;j<m;j++)
        {
            double dist1=calcdist(bobx[i], boby[i], dogx[j], dogy[j]);
            double dist2=calcdist(bobx[i+1], boby[i+1], dogx[j], dogy[j]);
            if(dist1+dist2<=dist0) vt[i].push_back(j);
        }
    }

    int rj=0;
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++)
    {
        memset(bio,0,sizeof(bio));
        rj+=upari(i);
    }
    cout << n+rj << endl;
    for(int i=0;i<n;i++)
    {
        cout << bobx[i] << " " << boby[i] << " ";
        for(int j=0;j<m;j++)
            if(par[j]==i) cout << dogx[j] << " " << dogy[j] << " ";
    }

}
