#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ucenici[100];

int main()
{
    string ulaz;
    int i;
    for(i=0;true;i++)
    {
        cin >> ulaz;
        ucenici[i]=ulaz;
        if(ulaz[ulaz.length()-1]!=',') break;
        else ucenici[i].erase(ulaz.length()-1);
    }
    int ucenika=i+1;
    bool na_listi, zadnji=false;
    for(i=0;true;i++)
    {
        cin >> ulaz;
        na_listi=false;
        if(ulaz[ulaz.length()-1]==',') ulaz.erase(ulaz.length()-1);
        else zadnji=true;
        for(i=0;i<ucenika;i++)
            if(ulaz.compare(ucenici[i])==0)
            {
                ucenici[i]="";
                na_listi=true;
                break;
            }
        if(zadnji) break;
    }

    sort(ucenici, ucenici+ucenika);
    bool prvi=true;
    for(i=ucenika-1;ucenici[i]!="";i--)
    {
        if(!prvi) cout << ", ";
        cout << ucenici[i];
        prvi=false;
    }
    if(prvi) cout << "SVI SU";
}
