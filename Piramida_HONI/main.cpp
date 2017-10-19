//NEDOVRSENO
#include <cstdio>
#include <cstring>
using namespace std;

int p[26][100001];

long long f(char c, int l, int h)
{
    return p[c][h]-p[c][l];
}

int main()
{
    int n, k;
    char rijec[100001];
    scanf("%i %s %i", &n, &rijec, &k);
    int len=strlen(rijec);
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<26;j++)
            p[j][i]=p[j][i-1];
        p[rijec[i-1]-'A'][i]++;
    }

    int a, poc;
    char c;
    for(int i=0;i<k;i++)
    {
        scanf("%i %c", &a, &c);
        if(a%2)
            poc=((((a-1)/2)%len) * (a%len))%len;
        else
            poc=(((a-1)%len) * ((a/2)%len))%len;
        c-='A';
        printf("%lli\n", f(c, poc, len) + a/len*p[c][len] + f(c, 0, a-a/len*len-(len-poc)));
    }
}
