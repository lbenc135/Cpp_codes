#include <iostream>
using namespace std;

char polje[8][8];

int main()
{
    char zn;
    int x1, y1, x=0, a, b;
    bool m=false;
    cin >> zn >> x1;
    y1=(int)zn-65;
    x1--;
    a=x1; b=y1;
    if(x1>0)
    {
        if(y1>0)
            polje[x1-1][y1-1]='x';
        polje[x1-1][y1]='x';
        if(y1<7)
            polje[x1-1][y1+1]='x';
    }
    if(y1>0)
    {
        polje[x1][y1-1]='x';
        if(x<7)
            polje[x1+1][y1-1]='x';
    }
    if(x<7)
    {
        polje[x1+1][y1]='x';
        if(y1<7)
        polje[x1+1][y1+1]='x';
    }
    if(y1<7)
        polje[x1][y1+1]='x';

    polje[a][b]='M';

    cin >> zn >> x1;
    y1=(int)zn-65;
    x1--;
    for(int i=0;i<8;i++)
    {
        polje[x1][i]='.';
        polje[i][y1]='.';
    }
    polje[x1][y1]='T';
    cin >> zn >> x1;
    x1--;
    y1=(int)zn-65;
    for(int i=0;i<8;i++)
    {
        polje[x1][i]='.';
        polje[i][y1]='.';
    }
    polje[x1][y1]='T';
    cin >> zn >> x1;
    x1--;
    y1=(int)zn-65;
    polje[x1-1][y1-1]='.';
    polje[x1][y1-1]='.';
    polje[x1-1][y1]='.';
    polje[x1-1][y1+1]='.';
    polje[x1+1][y1-1]='.';
    polje[x1][y1+1]='.';
    polje[x1+1][y1]='.';
    polje[x1+1][y1+1]='.';
    polje[x1][y1]='K';

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(polje[i][j]=='x') x++;
            else if(polje[i][j]=='M') m=true;
            cout << polje[i][j];
        }
        cout << endl;
    }



    if(m==true && x>0)
        cout << "trk " << x;
    else if(m==false && x==0)
        cout << "mat";
    else if(m==false && x>0)
        cout << "sah " << x;
    else
        cout << "pat";
}
