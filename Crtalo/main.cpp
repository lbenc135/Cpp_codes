#include <iostream>
using namespace std;

int main()
{
    int n, a=0, b=0;
    cin >> n;
    char papir[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            papir[i][j]='.';
    char naredbe[250];
    cin >> naredbe;
    for(int i=0;i<250;i++)
    {
        if(papir[a][b]=='.')
        {
            if(naredbe[i]=='D' && a<n-1)
                papir[a][b]='|';
            else if(naredbe[i]=='U' && a>0)
                papir[a][b]='|';
            else if(naredbe[i]=='R' && b<n-1)
                papir[a][b]='-';
            else if(naredbe[i]=='L' && b>0)
                papir[a][b]='-';
        }
        else if(papir[a][b]=='-')
        {
            if(naredbe[i]=='D' && a<n-1)
                papir[a][b]='+';
            else if(naredbe[i]=='U' && a>0)
                papir[a][b]='+';
        }
        else if(papir[a][b]=='|')
        {
            if(naredbe[i]=='R' && b<n-1)
                papir[a][b]='+';
            else if(naredbe[i]=='L' && b>0)
                papir[a][b]='+';
        }

        if(naredbe[i]=='D' && a<n-1)
            papir[++a][b]='|';
        else if(naredbe[i]=='U' && a>0)
            papir[--a][b]='|';
        else if(naredbe[i]=='R' && b<n-1)
            papir[a][++b]='-';
        else if(naredbe[i]=='L' && b>0)
            papir[a][--b]='-';

        if(naredbe[i]!='D' && naredbe[i]!='U' && naredbe[i]!='R' && naredbe[i]!='L') break;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << papir[i][j];
        cout << endl;
    }

}
