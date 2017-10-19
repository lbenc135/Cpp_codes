#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1048576

typedef pair<int,int> par;
par T[MAXN];
int gdje[MAXN];
int n, N=1;

void update(int p)
{
    T[p+N].first = gdje[p];
    T[p+N].second = gdje[p];
    p += N;
    for(p/=2; p>0; p/=2)
    {
        T[p].first = min(T[p*2].first, T[p*2+1].first);
        T[p].second = max(T[p*2].second, T[p*2+1].second);
    }
}

par upit(int cvor, int x, int y, int a, int b)
{
    if(x>=a && y<=b) return T[cvor];
    if(x>b ||  y<a) return par(1000000, -1);
    int mid = (x+y)/2;
    par lijevi = upit(cvor*2, x, mid, a, b);
    par desni = upit(cvor*2+1, mid+1, y, a, b) ;
    par vrati;
    vrati.first = min(lijevi.first, desni.first);
    vrati.second = max(lijevi.second, desni.second);
    return vrati;
}

int main()
{
    int m;
    cin>>n>>m;
    while(N<n) N*=2;
    int niz[n];
    for(int i=0; i<n; i++)
    {
        cin>>niz[i];
        gdje[niz[i]] = i+1;
    }

    for(int i = 0; i<MAXN; i++)
    {
        T[i].first = 1000000;
        T[i].second = -1;
    }
    for(int i=1; i<=n; i++)
        update(i);

    for(int i=0; i<m; i++)
    {
        int z, x, y;
        cin>>z>>x>>y;
        if(z==1)
        {
            x--; y--;
            swap(gdje[niz[x]],gdje[niz[y]]);
            update(niz[x]);
            update(niz[y]);
            swap(niz[x], niz[y]);
        }
        else
        {
            par p = upit(1,0,N-1,x,y);
            if(p.second-p.first == y-x)
                cout<<"DA"<<endl;
            else
                cout<<"NE"<<endl;
        }

    }

    return 0;
}
