#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, br=0;
    cin >> n;
    string rijec[n];
    bool ab, bb, add;
    int a, b;
    for(int i=0;i<n;i++)
    {
        cin >> rijec[i];
        add=true;
        ab=false; bb=false;
        for(int j=0;j<rijec[i].length();j++)
        {
            if(rijec[i][j]=='A' && ab==false) {ab=true; a=j;}
            else if(rijec[i][j]=='A' && ab==true && bb==false) ab=false;
            else if(rijec[i][j]=='A' && ab==true && bb==true && a<b) {add=false; break;}
            else if(rijec[i][j]=='A' && ab==true && bb==true && a>b) {ab=false;}
            else if(rijec[i][j]=='B' && bb==false) {bb=true; b=j;}
            else if(rijec[i][j]=='B' && bb==true && ab==false) bb=false;
            else if(rijec[i][j]=='B' && bb==true && ab==true && b<a) {add=false; break;}
            else if(rijec[i][j]=='B' && bb==true && ab==true && b>a) {bb=false;}
        }
        if(add && ab==false && bb==false) br++;
    }

    cout << br;
}
