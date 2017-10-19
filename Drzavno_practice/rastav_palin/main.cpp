#include <cstdio>
#include <cstring>
using namespace std;

char s[100];
int stanje[100][100];

bool isPalin(int a, int b)
{
    int mid=(b-a+2)/2;
    for(int i=0;i<mid;i++)
        if(s[a+i]!=s[b-i]) return false;
    return true;
}

int rast(int a, int b)
{
    if(a==b) return 0;
    if(stanje[a][b]!=-1) return stanje[a][b];
    if(isPalin(a, b)) return stanje[a][b]=0;

    int rj=100000000;
    for(int i=a;i<b;i++)
    {
        if(rast(a, i)+rast(i+1, b)+1<rj)
            rj=rast(a, i)+rast(i+1, b)+1;
    }
    return stanje[a][b]=rj;
}

int main()
{
    memset(stanje, -1, sizeof(stanje));

    scanf("%s", s);
    printf("%i", rast(0, strlen(s)-1)+1);
}
