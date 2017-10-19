#include <cstdio>
#include <cstring>
using namespace std;

char s1[100], s2[100];
int stanje[100][100];

int nzp(int f, int s)
{
    if(f<0 || s<0) return 0;
    if(stanje[f][s]!=-1) return stanje[f][s];

    if(s1[f]==s2[s])
        return stanje[f][s]=nzp(f-1, s-1)+1;
    else if(nzp(f-1, s)>nzp(f, s-1))
        return stanje[f][s]=nzp(f-1, s);
    else
        return stanje[f][s]=nzp(f, s-1);
}

int main()
{
    memset(stanje, -1, sizeof(stanje));
    scanf("%s %s", &s1, &s2);
    int l1=strlen(s1), l2=strlen(s2);
    printf("%i\n", nzp(l1-1, l2-1));
}
