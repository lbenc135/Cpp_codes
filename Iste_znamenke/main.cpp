#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool is_rev_sorted(char s[1000], int len)
{
    for(int i=1;i<len;i++)
        if(s[i]>s[i-1]) return false;
    return true;
}

int main()
{
    char s[1000];
    scanf("%s", &s);
    int len=strlen(s);

    if(is_rev_sorted(s, len))
        printf("Ne postoji!\n");
    else
        for(int i=len-2;i>=0;i--)
            if(s[i]<s[i+1])
            {
                sort(s+i+1, s+len);
                swap(s[i], s[i+1]);
                printf("%s\n", s);
                break;
            }
}
