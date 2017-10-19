#include <iostream>
#include <algorithm>
using namespace std;

int stanje[100][100];
int polje[100][100];

int main()
{
    int t, h, w, maks;
    cin >> t;
    for(int a=0;a<t;a++)
    {
        maks=0;
        cin >> h >> w;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin >> polje[i][j];

        for(int i=0;i<w;i++)
            stanje[0][i]=polje[0][i];
        for(int i=1;i<h;i++)
            for(int j=0;j<w;j++)
            {
                if(j==0)
                    stanje[i][j]=max(stanje[i-1][j], stanje[i-1][j+1])+polje[i][j];
                else if(j==w-1)
                    stanje[i][j]=max(stanje[i-1][j], stanje[i-1][j-1])+polje[i][j];
                else
                    stanje[i][j]=max(stanje[i-1][j], max(stanje[i-1][j-1], stanje[i-1][j+1]))+polje[i][j];
            }
        for(int i=0;i<w;i++)
            if(stanje[h-1][i]>maks) maks=stanje[h-1][i];
        cout << maks << endl;
    }
}
