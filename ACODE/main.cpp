#include <cstdio>
#include <cstring>
using namespace std;

char e[5001];
long long rez[5001]={1, 1};

int main()
{
    while(1)
    {
        scanf("%s", &e);
        int len=strlen(e);
        if(len==1 && e[0]=='0') break;
        for(int i=2;i<=len;i++)
        {
            if((e[i-2]<'2' || (e[i-2]=='2' && e[i-1]<='6')) && e[i-1]!='0' && e[i]!='0' && e[i-2]!='0')
                rez[i]=rez[i-1]+rez[i-2];
            else if(e[i-2]>'2' && e[i-1]=='0')
            {
                rez[len]=0;
                break;
            }
            else
                rez[i]=rez[i-1];
        }
        printf("%lli\n", rez[len]);
    }
}
