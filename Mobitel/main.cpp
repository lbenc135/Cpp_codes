#include <cstdio>
#include <cstring>
using namespace std;

int sl[27]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main()
{
    int br[10], tp;
    for(int i=0;i<9;i++)
    {
        scanf("%i", &tp);
        br[tp]=i+1;
    }
    char rijec[101];
    scanf("%s", rijec);
    int len=strlen(rijec), prev=-1, tren, md;
    for(int i=0;i<len;i++)
    {
        tren=sl[rijec[i]-'a'];
        md=0;
        for(int j=rijec[i]-'a';sl[j]==tren && j>=0;j--)
            md++;
        if(tren==prev) printf("#");
        for(int j=0;j<md;j++) printf("%i", br[tren]);
        prev=tren;
    }
}
