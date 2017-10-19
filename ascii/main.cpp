#include <iostream>
#include <cstring>
using namespace std;

int dfs(int x, int y);

char polje[102][102];
int r, s;
bool obris[102][102];
int rubni=0;

int main()
{
    cin >> r >> s;
    memset(polje, '.', sizeof(polje));
    for(int i=1;i<=r;i++)
        for(int j=1;j<=s;j++)
            cin >> polje[i][j];

    long povrsina=0;
    dfs(0, 0);

    for(int i=1;i<=r;i++)
        for(int j=1;j<=s;j++)
            if(polje[i][j]!='+') povrsina++;


    povrsina-=rubni/2;
    cout << povrsina;
}

int dfs(int x, int y)
{
    if(x<0 || y<0 || x>r+1 || y>s+1) return 0;
    if(polje[x+1][y+1]=='.' && polje[x+1][y]!='/') {polje[x+1][y+1]='+'; dfs(x+1, y+1);}
    if(polje[x+1][y-1]=='.' && polje[x+1][y]!='\\') {polje[x+1][y-1]='+'; dfs(x+1, y-1);}
    if(polje[x-1][y-1]=='.' && polje[x-1][y]!='/') {polje[x-1][y-1]='+'; dfs(x-1, y-1);}
    if(polje[x-1][y+1]=='.' && polje[x-1][y]!='\\') {polje[x-1][y+1]='+'; dfs(x-1, y+1);}
    if(polje[x+1][y]=='.') {polje[x+1][y]='+'; dfs(x+1, y);}
    if(polje[x-1][y]=='.') {polje[x-1][y]='+'; dfs(x-1, y);}
    if(polje[x][y+1]=='.') {polje[x][y+1]='+'; dfs(x, y+1);}
    if(polje[x][y-1]=='.') {polje[x][y-1]='+'; dfs(x, y-1);}

    if((polje[x+1][y+1]=='/' || polje[x+1][y+1]=='\\') && obris[x+1][y+1]==false && polje[x+1][y]!='/') {rubni++; obris[x+1][y+1]=true;}
    if((polje[x-1][y-1]=='/' || polje[x-1][y-1]=='\\') && obris[x-1][y-1]==false && polje[x-1][y]!='/') {rubni++; obris[x-1][y-1]=true;}
    if((polje[x+1][y-1]=='/' || polje[x+1][y-1]=='\\') && obris[x+1][y-1]==false && polje[x+1][y]!='\\') {rubni++; obris[x+1][y-1]=true;}
    if((polje[x-1][y+1]=='/' || polje[x-1][y+1]=='\\') && obris[x-1][y+1]==false && polje[x-1][y]!='\\') {rubni++; obris[x-1][y+1]=true;}
    if((polje[x+1][y]=='/' || polje[x+1][y]=='\\') && obris[x+1][y]==false) {rubni++; obris[x+1][y]=true;}
    if((polje[x-1][y]=='/' || polje[x-1][y]=='\\') && obris[x-1][y]==false) {rubni++; obris[x-1][y]=true;}
    if((polje[x][y+1]=='/' || polje[x][y+1]=='\\') && obris[x][y+1]==false) {rubni++; obris[x][y+1]=true;}
    if((polje[x][y-1]=='/' || polje[x][y-1]=='\\') && obris[x][y-1]==false) {rubni++; obris[x][y-1]=true;}
}
