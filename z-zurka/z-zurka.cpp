#include <iostream>
#include <map>
using namespace std;

int main()
{
    int nc=0, temp, cities, maxc=0;
    map<int,int> town;
    for(int i=0;i<3;i++)
    {
        cin >> cities;
        for(int j=0;j<cities;j++)
        {
            cin >> temp;
            town[temp]++;
            if(temp>maxc) maxc=temp;
        }
    }
    for(int i=0;i<=maxc;i++)
    {
        if(town[i]==3)
            nc++;
    }
    cout << nc << endl;
}
