#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int brojevi[n];
    int tablica[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> tablica[i][j];

    if(n==2) cout << 1 << " " << 1;
    else
    {
        brojevi[0] = (tablica[0][2]-tablica[1][2] + tablica[0][1])/2;
        cout << brojevi[0] << " ";
        for(int i=1;i<n;i++)
            cout << (brojevi[i] = tablica[i-1][i] - brojevi[i-1]) << " ";
    }
}
