#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    char n[101][10];
    scanf("%i", &t);
    for(int i=0;i<t;i++)
        scanf("%s", &n[i]);
    for(int i=0;i<t;i++)
    {
        int mini=100000000, maxi=0, minit, maxit;
        int len=strlen(n[i]);
        if(len>1)
        {
            for(int j=0;j<len;j++)
            {
                if(n[i][j]>maxi) { maxi=n[i][j]; maxit=j; }
                if(n[i][j]<mini && n[i][j]!='0') { mini=n[i][j]; minit=j; }
            }
            swap(n[i][0], n[i][minit]);
            printf("Case #%i: %s ", i+1, n[i]);
            swap(n[i][0], n[i][minit]);
            swap(n[i][0], n[i][maxit]);
            printf("%s\n", n[i]);
        }
        else
            printf("Case #%i: %s %s\n", i+1, n[i], n[i]);
    }
}
