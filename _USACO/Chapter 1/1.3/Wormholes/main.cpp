/*
ID: lbenc131
PROG: wormhole
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, rez=0;
int p[13], desni[13];
pair<int,int> w[13];

bool isGood()
{
    int cur;
    for(int i=0;i<n;i++)
    {
        bool visited[13]={0}, no=false;
        cur=i;
        for(int c=0;c<n;c++)
        {
            cur=p[desni[cur]+1]-1;
            if(cur==-1) {no=true; break;}
        }
        if(!no) return true;
    }
    return false;
}

void solve()
{
    int i;
    for(i=1;i<=n;i++)
        if(p[i]==0) break;

    if(i>n && isGood())
        rez++;

    for(int j=i+1;j<=n;j++)
        if(p[j]==0)
        {
            p[i]=j;
            p[j]=i;
            solve();
            p[i]=p[j]=0;
        }
}

int main() {
    FILE *fin  = fopen ("wormhole.in", "r");
    FILE *fout = fopen ("wormhole.out", "w");

    fscanf(fin, "%i", &n);
    for(int i=0;i<n;i++)
        fscanf(fin, "%i %i", &w[i].first, &w[i].second);

    for(int i=0;i<n;i++)
    {
        int mini=1000000000, it=-1;
        for(int j=0;j<n;j++)
            if(w[j].second==w[i].second && w[j].first>w[i].first && w[j].first<mini)
                { mini=w[j].first; it=j; }
        desni[i]=it;
    }

	solve();

	fprintf(fout, "%i\n", rez);
    return 0;
}
