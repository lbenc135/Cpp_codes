#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ED(int i, int j);

char s1[2001], s2[2001];
int stanje[2001][2001];

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        memset(stanje, 0, sizeof(stanje));
        scanf("%s %s", &s1, &s2);
        printf("%i\n", ED(strlen(s1), strlen(s2)));
    }
}

int ED(int i, int j)
{
    if(i==0) return j;
    if(j==0) return i;
    if(stanje[i][j]) return stanje[i][j];

    if(s1[i-1]==s2[j-1])
        return stanje[i][j]=ED(i-1, j-1);
    else
        return stanje[i][j]=min(ED(i-1, j)+1, min(ED(i, j-1)+1, ED(i-1, j-1)+1));
}
