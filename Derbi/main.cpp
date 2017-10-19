#include <iostream>
#include <cstring>
using namespace std;

int findparent(int x);
bool preklapanje(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

int parent[1001];

int main()
{
    int n;
    cin >> n;
    int x[n], y[n], x2[n], y2[n];
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i] >> x2[i] >> y2[i];
        parent[i]=i;
    }

    int povrsina[n], minx, miny, maxp=0;
    memset(povrsina, 0, sizeof(povrsina));
    bool dodan[n];
    memset(dodan, false, sizeof(dodan));
    for(int i=0;i<n;i++)
    {
        povrsina[i]=(x2[i]-x[i])*(y2[i]-y[i]);
        minx=1000000; miny=1000000;
        for(int j=i+1;j<n;j++)
        {
            if(!dodan[j] && preklapanje(x[i], y[i], x2[i], y2[i], x[j], y[j], x2[j], y2[j]))
            {
                parent[j]=findparent(i);
                povrsina[parent[j]]+=(x2[j]-x[j])*(y2[j]-y[j]);

                if(x2[i]-x[i]<minx) minx=x2[i]-x[i];
                if(x2[j]-x[j]<minx) minx=x2[j]-x[j];
                if(x2[j]-x[i]<minx) minx=x2[j]-x[i];
                if(x2[i]-x[j]<minx) minx=x2[i]-x[j];

                if(y2[i]-y[i]<miny) miny=y2[i]-y[i];
                if(y2[j]-y[j]<miny) miny=y2[j]-y[j];
                if(y2[j]-y[i]<miny) miny=y2[j]-y[i];
                if(y2[i]-y[j]<miny) miny=y2[i]-y[j];

                povrsina[parent[j]]-=minx*miny;
                dodan[j]=true;
            }
        }
    }

    for(int i=0;i<n;i++)
        if(povrsina[i]>maxp) maxp=povrsina[i];
    cout << maxp;
}

bool preklapanje(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if((x3<=x2 && x3>=x1 || x4<=x2 && x4>=x1) && y3>=y2 && y4<=y1) return true;
    if((x3<=x2 && x3>=x1 || x4<=x2 && x4>=x1) && y3<=y2 && y4>=y1) return true;
    if((y3>=y2 && y3<=y1 || y4>=y2 && y4<=y1) && x3<=x2 && x4>=x1) return true;
    if((y3>=y2 && y3<=y1 || y4>=y2 && y4<=y1) && x3>=x2 && x4<=x1) return true;
    return false;
}

int findparent(int x)
{
    if(x!=parent[x])
        parent[x]=findparent(parent[x]);
    return parent[x];
}
