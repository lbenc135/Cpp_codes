#include <iostream>
using namespace std;

int main()
{
    int oko[8]={1, -1, 1, -1, 0, 0, -1, 1};
    int oko2[8]={0, 0, 1, -1, 1, -1, 1, -1};
    char polje[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin >> polje[i][j];

    int x, y, maxi=0, br, br1;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(polje[i][j]=='.')
            {
                br=0;
                for(int k=0;k<8;k++)
                {
                    br1=0;
                    x=i+oko[k]; y=j+oko2[k];
                    if(polje[x][y]=='B')
                    {
                        while(polje[x][y]=='B')
                        {
                            br1++;
                            x+=oko[k]; y+=oko2[k];
                        }
                        if(polje[x][y]=='C') br+=br1;
                    }
                }
                if(maxi<br) maxi=br;
            }
        }

    cout << maxi;
}
