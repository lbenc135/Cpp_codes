#include <cstdio>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

char n[100001];

int main()
{
    scanf("%s", &n);
    int len=strlen(n);
    sort(n, n+len, greater<char>());

    int zbroj=0;
    if(n[len-1]=='0')
    {
        for(int i=0;i<len;i++)
            zbroj+=n[i]-'0';

        if(zbroj%3==0) {printf("%s", n); return 0;}
    }

    printf("-1");
}
