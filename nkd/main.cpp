#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k, n, pt=-1;
    cin >> k >> n;
    string lista[n];
    string temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        pt++;
        lista[pt] = temp;
        for(int i=0;i<pt-1;i++)
        {
            if(lista[i]==temp) lista[i]="";
        }
    }
    int i=pt;
    while(k>0 && i>=0)
    {
        if(lista[i]!="") {cout << lista[i] << endl; k--;}
        i--;
    }

}
