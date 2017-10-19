#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s1[100], s2[100];

int ed(int i, int j)
{
    if(i==0) return j;
    if(j==0) return i;

    if(s1[i-1]==s2[j-1])
        return ed(i-1, j-1);
    else
        return min(ed(i-1, j)+1, min(ed(i, j-1)+1, ed(i-1, j-1)+1));
}

int main()
{
    scanf("%s %s", s1, s2);
    int l1=strlen(s1), l2=strlen(s2);
    printf("%i", ed(l1, l2));
}
