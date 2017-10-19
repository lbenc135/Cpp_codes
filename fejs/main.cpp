#include <iostream>
using namespace std;

int addf(int a, int b);
bool checkf();
void refreshf();

int f[51][51];
int n;

int main()
{
    int m;
    cin >> n >> m;
    int a, b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        f[a][b] = f[b][a] = 1;
    }
    for(int i=0;i<=n;i++)
        f[i][i]=1;

    int dana=0, pr[51]={0};
    while(!checkf())
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(f[i][j]==1)
                    { pr[dana]+=addf(i, j); }
            }
        }
        dana++;
        refreshf();
    }

    cout << dana << endl;
    for(int i=0;i<dana;i++)
        cout << pr[i] << endl;
}

int addf(int a, int b)
{
    int pr=0;
    for(int i=1;i<=n;i++)
    {
        if(f[b][i]==1 && f[a][i]==0)
        {
            f[a][i] = f[i][a] = 2;
            pr++;
        }
    }
    return pr;
}

bool checkf()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]==0) return false;
    return true;
}

void refreshf()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]==2) f[i][j] = f[j][i] = 1;
}
