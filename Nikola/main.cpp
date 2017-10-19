#include <iostream>
#include <cstring>
using namespace std;

int n;
int pay[1000];
int stanje[1000][1000];

int opt(int polje, int skok)
{
    if(polje < 0 || polje >= n) return 1000000000;
    if(polje == n-1) return pay[polje];

    if(stanje[polje][skok] != -1) return stanje[polje][skok];

    return stanje[polje][skok] = pay[polje] + min(opt(polje-skok, skok), opt(polje+skok+1, skok+1));
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    cin >> pay[i];

    memset(stanje, -1, sizeof stanje);

    cout << opt(1,1);
}
