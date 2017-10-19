#include <iostream>
using namespace std;

int n, m;
pair<int,int> p[401];

bool check(int bit)
{
    for(int i=0;i<m;i++)
      if((bit&(1<<(p[i].first-1)))>0 && (bit&(1<<(p[i].second-1)))>0)
          return false;

    return true;
}

int main()
{
    int bit=0;

    cin >> n >> m;
    for(int i=0;i<m;i++)
      cin >> p[i].first >> p[i].second;

    int H = 1<<n;
    int zbr=0;
    for(int i=0;i<H;i++)
    {
        if(check(bit))
          zbr++;
        bit++;
    }

    cout << zbr;
}
