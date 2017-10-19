#include <iostream>
using namespace std;

char kolo[25];

int main()
{
    int n, k;
    cin >> n >> k;
    int s, pt=0;
    char sl;
    for(int i=0;i<k;i++)
    {
        cin >> s >> sl;
        pt=(pt+s)%n;
        if(kolo[pt]!='\0' && kolo[pt]!=sl) {cout << '!'; return 0;}
        else kolo[pt]=sl;
    }

    for(int i=pt;i>=0;i--)
    {
        if(kolo[i]!='\0') cout << kolo[i];
        else cout << '?';
    }
    for(int i=n-1;i>pt;i--)
    {
        if(kolo[i]!='\0') cout << kolo[i];
        else cout << '?';
    }
}
