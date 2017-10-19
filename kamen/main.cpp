#include <iostream>
using namespace std;

int main()
{
    int r, s, k;
    cin >> r >> s;
    char polje[r][s];
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            cin >> polje[i][j];
    cin >> k;
    int stupac[k];
    for(int i=0;i<k;i++)
    {
        cin >> stupac[i];
        stupac[i]--;
        for(int j=1;j<r;j++)
        {
            if(polje[j][stupac[i]]=='#')
            {
                polje[j-1][stupac[i]]='o';
                break;
            }
            else if(polje[j][stupac[i]]=='o')
            {
                if(polje[j-1][stupac[i]+1]=='.' && polje[j][stupac[i]+1]=='.')
                    {stupac[i]++; j--;}
                else if(polje[j-1][stupac[i]-1]=='.' && polje[j][stupac[i]-1]=='.')
                    {stupac[i]--; j--;}
                else
                    polje[j-1][stupac[i]]='o';

            }
            else if(j==r-1)
            {
                polje[j][stupac[i]]='o';
                break;
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
            cout << polje[i][j];
        cout << endl;
    }

}
