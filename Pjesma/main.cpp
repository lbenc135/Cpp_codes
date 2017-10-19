#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m, pogodenih=0, pol, odg;
    cin >> n;
    string naslov[n];
    for(int i=0;i<n;i++)
        cin >> naslov[i];

    if(n%2==0) pol=n/2;
    else pol=n/2+1;

    cin >> m;
    string pjesma[m];
    for(int i=0;i<m;i++)
    {
        cin >> pjesma[i];
        for(int j=0;j<n;j++)
            if(pjesma[i]==naslov[j]) {pogodenih++; naslov[j]="";}
        if(pogodenih==pol) {odg=i+1; pol=-1;}
    }
    cout << odg;
}
