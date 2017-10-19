#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int zn[10];
    for(int i=0;i<10;i++)
        zn[i]=0;
    int cities, cits, index;
    cin >> cities;
    for(int i=0;i<cities;i++)
    {
        cin >> cits;
        index=(int)(cits)/(pow(10, (int)log10(cits)));
        zn[index]++;
    }
    if(zn[1]>=zn[2] and zn[2]>=zn[3] and zn[3]>=zn[4] and zn[4]>=zn[5] and zn[5]>=zn[6] and zn[6]>=zn[7] and zn[7]>=zn[8] and zn[8]>=zn[9])
    {
        cout << 0;
    }
    else
    {
        for(int test=1;test<9;test++)
        {
            if(zn[test]<zn[test+1])
            {
                cout << test << " " << zn[test] << " " << zn[test+1];
                break;
            }
        }
    }
}
