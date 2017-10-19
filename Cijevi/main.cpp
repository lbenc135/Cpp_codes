#include <iostream>
using namespace std;

bool DFS(int x, int y);

char polje[27][27];
char kretanje[27][27];
bool visited[27][27];
int mov[8] = {1, -1, 0, 0, 0, 0, 1, -1};

int main()
{
    int r, s;
    cin >> r >> s;

    int xm, ym;
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
        {
            cin >> polje[i][j];
            if(polje[i][j]=='M')
                { xm = i; ym = j; }
        }

    char znak[7] = {'|', '-', '+', '1', '2', '3', '4'};
    bool found = false;
    int rx, ry;
    char rz;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(polje[i][j]!='.') continue;

            for(int k=0;k<7;k++)
            {
                for(int l=0;l<27;l++)
                    for(int m=0;m<27;m++)
                        visited[l][m]=false;

                polje[i][j] = znak[k];
                if(DFS(xm, ym))
                {
                    rx = i+1; ry = j+1; rz = znak[k];
                    found = true;
                    break;
                }
            }
            if(found)
                break;
            polje[i][j]='.';
        }
        if(found)
            break;
    }


    cout << rx << " " << ry << " " << rz;
}

bool DFS(int x, int y)
{
    visited[x][y]=true;
    if(polje[x][y]=='Z') return true;

    if(polje[x][y]=='M')
    {
        if(polje[x][y+1]=='-' || polje[x][y+1]=='3' || polje[x][y+1]=='4' || polje[x][y+1]=='+')
        {
            kretanje[x][y+1] = 'R';
            if(DFS(x, y+1)) return true;
        }
        else if(y-1>=0 && (polje[x][y-1]=='-' || polje[x][y-1]=='1' || polje[x][y-1]=='2' || polje[x][y-1]=='+'))
        {
            kretanje[x][y-1] = 'L';
            if(DFS(x, y-1)) return true;
        }
        else if(x-1>=0 && (polje[x-1][y]=='|' || polje[x-1][y]=='1' || polje[x-1][y]=='4' || polje[x-1][y]=='+'))
        {
            kretanje[x-1][y] = 'U';
            if(DFS(x-1, y)) return true;
        }
        else if(polje[x+1][y]=='-' || polje[x+1][y]=='2' || polje[x+1][y]=='3' || polje[x+1][y]=='+')
        {
            kretanje[x+1][y] = 'D';
            if(DFS(x+1, y)) return true;
        }
    }
    else if(polje[x][y]=='|')
    {
        if(kretanje[x][y]=='D' && (visited[x+1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x+1][y] = 'D';
            if(DFS(x+1, y)) return true;
        }
        else if(kretanje[x][y]=='U' && (visited[x-1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x-1][y] = 'U';
            if(DFS(x-1, y)) return true;
        }
    }
    else if(polje[x][y]=='-')
    {
        if(kretanje[x][y]=='R' && (visited[x][y+1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y+1] = 'R';
            if(DFS(x, y+1)) return true;
        }
        else if(kretanje[x][y]=='L' && (visited[x][y-1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y-1] = 'L';
            if(DFS(x, y-1)) return true;
        }
    }
    else if(polje[x][y]=='+')
    {
        if(kretanje[x][y]=='D' && (visited[x+1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x+1][y] = 'D';
            if(DFS(x+1, y)) return true;
        }
        else if(kretanje[x][y]=='U' && (visited[x-1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x-1][y] = 'U';
            if(DFS(x-1, y)) return true;
        }
        else if(kretanje[x][y]=='R' && (visited[x][y+1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y+1] = 'R';
            if(DFS(x, y+1)) return true;
        }
        else if(kretanje[x][y]=='L' && (visited[x][y-1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y-1] = 'L';
            if(DFS(x, y-1)) return true;
        }
    }
    else if(polje[x][y]=='1')
    {
        if(kretanje[x][y]=='L' && (visited[x+1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x+1][y] = 'D';
            if(DFS(x+1, y)) return true;
        }
        else if(kretanje[x][y]=='U' && (visited[x][y+1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y+1] = 'R';
            if(DFS(x, y+1)) return true;
        }
    }
    else if(polje[x][y]=='2')
    {
        if(kretanje[x][y]=='D' && (visited[x][y+1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y+1] = 'R';
            if(DFS(x, y+1)) return true;
        }
        else if(kretanje[x][y]=='L' && (visited[x-1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x-1][y] = 'U';
            if(DFS(x-1, y)) return true;
        }
    }
    else if(polje[x][y]=='3')
    {
        if(kretanje[x][y]=='D' && (visited[x][y-1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y-1] = 'L';
            if(DFS(x, y-1)) return true;
        }
        else if(kretanje[x][y]=='R' && (visited[x-1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x-1][y] = 'U';
            if(DFS(x-1, y)) return true;
        }
    }
    else if(polje[x][y]=='4')
    {
        if(kretanje[x][y]=='U' && (visited[x][y-1]==false || polje[x][y-1]=='+'))
        {
            kretanje[x][y-1] = 'L';
            if(DFS(x, y-1)) return true;
        }
        else if(kretanje[x][y]=='R' && (visited[x+1][y]==false || polje[x][y-1]=='+'))
        {
            kretanje[x+1][y] = 'D';
            if(DFS(x+1, y)) return true;
        }
    }

    return false;
}
