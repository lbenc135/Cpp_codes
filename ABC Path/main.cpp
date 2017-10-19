#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int abc(int x, int y);

char polje[50][50];
int h, w;
int a1[]={-1,0,1,0,1,-1,-1,1};
int a2[]={0,1,0,-1,1,-1,1,-1};
int memo[50][50];

int main()
{
    vector<pair<int, int> > a;
    int maxi;
    for(long long k=1;;k++)
    {
        maxi=0;
        a.clear();
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                memo[i][j]=-1;
        cin >> h >> w;
        if(h==0 && w==0) break;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                cin >> polje[i][j];
                if(polje[i][j]=='A') a.push_back(make_pair(i, j));
            }

        for(int i=0;i<a.size();i++)
            if(abc(a[i].first, a[i].second)>maxi) maxi=abc(a[i].first, a[i].second);
        if(!a.empty()) maxi++;
        cout << "Case " << k << ": " << maxi << endl;
    }
}

int abc(int x, int y)
{
    if(memo[x][y]!=-1) return memo[x][y];
    int maks=0, x2, y2, temp;
    for(int i=0;i<8;i++)
    {
        x2=x+a1[i]; y2=y+a2[i];
        if(x2>=0 && x2<h && y2>=0 && y2<w && (int)polje[x2][y2]==polje[x][y]+1)
        {
            temp=abc(x2, y2)+1;
            if(temp>maks) maks=temp;
        }
    }
    return memo[x][y] = maks;
}
