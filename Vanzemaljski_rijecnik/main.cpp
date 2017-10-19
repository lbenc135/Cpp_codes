#include <iostream>
#include <string>
using namespace std;

int main()
{
    int l, d, rj=0;
    cin >> l >> d;
    string rijec[d], uzorak, slova[l];
    for(int i=0;i<d;i++)
        cin >> rijec[i];
    cin >> uzorak;

    bool unutra;
    for(int i=0, j=0;i<uzorak.length();i++)
    {
        if(uzorak[i]==')') {j++; unutra=false;}
        else if(uzorak[i]=='(') unutra=true;
        else
        {
            slova[j].push_back(uzorak[i]);
            if(!unutra) j++;
        }
    }

    bool moze;
    for(int i=0;i<d;i++)
    {
        moze=true; unutra=false;
        for(int j=0;j<l;j++)
        {
            if(slova[j].find(rijec[i][j])==string::npos) {moze=false; break;}
        }
        if(moze) rj++;
    }

    cout << rj;
}
