#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

pair<int,int> towers[40004];

struct sortBySecond
{
  bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right)
      {
         return (left.second < right.second);
       }
};

int main()
{
    int t, w, h, n;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i %i %i", &w, &h, &n);
        towers[0]=pair<int,int>(0,0);
        towers[1]=pair<int,int>(0,h+1);
        towers[2]=pair<int,int>(w+1,0);
        towers[3]=pair<int,int>(w+1,h+1);
        n+=4;
        for(int i=4;i<n;i++)
            scanf("%i %i", &towers[i].first, &towers[i].second);

        sort(towers, towers+n);
        int maxw=0, maxh=0;
        for(int i=1;i<n;i++)
        {
            if(towers[i].first-towers[i-1].first>maxw) maxw = towers[i].first-towers[i-1].first;
        }
        sort(towers, towers+n, sortBySecond());
        for(int i=1;i<n;i++)
        {
            if(towers[i].second-towers[i-1].second>maxh) maxh = towers[i].second-towers[i-1].second;
        }

        printf("%i\n", --maxh*--maxw);
    }
}
