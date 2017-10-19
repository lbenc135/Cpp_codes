#include <iostream>
using namespace std;

char findchar(int x, int y);
long calcdist(int x, int y, char s);

char slova[]={'Q','W','E','R','T','Y','U','I','O','P',
                'A','S','D','F','G','H','J','K','L',
                'Z','X','C','V','B','N','M'};

int main()
{
    int n, m;
    cin >> n >> m;
    int x[n], y[n];
    string rijec, rijecnik[m];
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    for(int i=0;i<m;i++)
        cin >> rijecnik[i];

    for(int i=0;i<n;i++)
        rijec.push_back(findchar(x[i], y[i]));
    cout << rijec << endl;

    long mind=1000000000, d, r;
    for(int i=0;i<m;i++)
    {
        d=0;
        for(int j=0;j<n;j++)
            d+=calcdist(x[j], y[j], rijecnik[i][j]);
        if(d<mind) {mind=d; r=i;}
    }
    cout << rijecnik[r];
}

char findchar(int x, int y)
{
    if(x<0 || y<0) return '?';
    if(y<=200)
    {
        x-=470;
        if(x%320<=300) return slova[x/320+19];
        else return '?';
    }
    else if(y<440)
    {
        if(y<220 || y>420) return '?';
        x-=150;
        if(x%320<=300) return slova[x/320+10];
        else return '?';
    }
    else if(y<=640)
    {
        if(x%320<=300) return slova[x/320];
        else return '?';
    }
    else return '?';
}


long calcdist(int x, int y, char s)
{
    int xs, ys;
    for(int i=0;i<26;i++)
    {
        if(slova[i]==s)
        {
            if(i<10)
            {
                ys=540;
                xs=i*320+150;
            }
            else if(i<19)
            {
                ys=320;
                xs=(i-10)*320+300;
            }
            else
            {
                ys = 100;
                xs = (i-19)*320+620;
            }
            break;
        }
    }

    return (x-xs)*(x-xs) + (y-ys)*(y-ys);
}
