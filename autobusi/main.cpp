#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int grupe[n];
    for(int i=0;i<n;i++)
    {
        cin >> grupe[i];
    }
    int m;
    cin >> m;
    int autob[m][2];
    for(int i=0;i<m;i++)
    {
        cin >> autob[i][0];
        cin >> autob[i][1];
    }

    int ostalo=n, grupa=0, bus=0;
    while(ostalo>0)
    {
        while(grupe[grupa]>autob[bus][1])
        {
            bus++;
            autob[bus][1]+=autob[bus-1][1];
        }
        if((grupe[grupa]<=autob[bus][1]))
            grupa++;bus++;ostalo--;
        if(ostalo==0) break;
        if((grupe[grupa]<=autob[bus-1][1]-grupe[grupa-1]))
        {
            grupa++;ostalo--;
        }
        while(grupe[grupa]<=autob[bus-1][1]-grupe[grupa-1] && grupa<n-1)
        {
            ostalo--;
            grupa++;
        }
    }
    cout << autob[bus-1][0]+1;
}
