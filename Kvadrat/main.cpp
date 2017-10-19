#include <iostream>
using namespace std;

void obojaj(int x, int y, int l);
bool isto();

char polje[8][8], pompolje[8][8];
int n;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> polje[i][j];
            pompolje[i][j]='.';
        }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<=n-max(i,j);k++)
            {
                obojaj(i, j, k);
                if(isto()) {cout << 1 << endl << i+1 << " " << j+1 << " " << k; return 0;}
                obojaj(i, j, k);
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<=n-max(i,j);k++)
            {
                obojaj(i, j, k);

                for(int l=0;l<n;l++)
                {
                    for(int m=0;m<n;m++)
                    {
                        for(int o=1;o<=n-max(l,m);o++)
                        {
                            obojaj(l, m, o);
                            if(isto()) {cout << 2 << endl << i+1 << " " << j+1 << " " << k << endl; cout << l+1 << " " << m+1 << " " << o; return 0;}
                            obojaj(l, m, o);
                        }
                    }
                }

                obojaj(i, j, k);
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<=n-max(i,j);k++)
            {
                obojaj(i, j, k);

                for(int l=0;l<n;l++)
                {
                    for(int m=0;m<n;m++)
                    {
                        for(int o=1;o<=n-max(l,m);o++)
                        {
                            obojaj(l, m, o);
                            for(int p=0;p<n;p++)
                            {
                                for(int q=0;q<n;q++)
                                {
                                    for(int r=1;r<=n-max(p,q);r++)
                                    {
                                        obojaj(p, q, r);
                                        if(isto()) {cout << 3 << endl << i+1 << " " << j+1 << " " << k << endl;
                                                    cout << l+1 << " " << m+1 << " " << o << endl; cout << p+1 << " " << q+1 << " " << r; return 0;}
                                        obojaj(p, q, r);
                                    }
                                }
                            }
                            obojaj(l, m, o);
                        }
                    }
                }

                obojaj(i, j, k);
            }
        }
    }
}

void obojaj(int x, int y, int l)
{
    for(int i=x;i<x+l;i++)
        for(int j=y;j<y+l;j++)
        {
            if(pompolje[i][j]=='.') pompolje[i][j]='#';
            else pompolje[i][j]='.';
        }
}

bool isto()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(polje[i][j]!=pompolje[i][j]) return false;
    return true;
}
