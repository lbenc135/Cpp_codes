#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, br=0;
    cin >> a >> b >> c;
    vector<pair<int, int> > kl;
    pair<int, int> coor;
    bool moze;

    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            moze=true;
            for(int k=0;k<kl.size();k++)
                if(abs(i-kl[k].first) + abs(j-kl[k].second)<=c)
                    moze=false;
            if(moze)
            {
                coor.first=i; coor.second=j;
                kl.push_back(coor);
                br++;
            }
        }

    cout << br;
}
