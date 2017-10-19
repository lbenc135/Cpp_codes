#include <iostream>
using namespace std;

int main()
{
    int r, s;
    cin >> r >> s;
    char polje[r][s];
    for(int i=0;i<r;i++)
        for(int j=0l;j<s;j++)
         cin >> polje[i][j];

    int poz[10], pz=1;
    bool pov;
    for(int i=s-2;i>0;i--)
    {
        pov=false;
        for(int j=0;j<r;j++)
            if(polje[j][i]!='.') {poz[polje[j][i]-'0']=pz; pov=true; polje[j][i-1]='.'; polje[j][i-2]='.';}
        if(pov) pz++;
    }
    for(int i=1;i<10;i++)
        cout << poz[i] << endl;
}
