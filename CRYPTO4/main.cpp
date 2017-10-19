#include <cstdio>
#include <cstring>
using namespace std;

#define MAXL 600000
#define MAXC 100001

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        int m;
        scanf("%i", &m);
        char x[MAXL], y[MAXL], k[MAXC], found[MAXL]={0};
        int len;
        scanf("%s%n %s", &x, &len, &y);
        len--;
        if(m>len) m = len;

        do
        {
            memset(k, -1, len);

            //Find cypher
            for(int i=0;i<len;i++)
            {
                if(x[i]!='*' && y[i]!='*')
                {
                    int yt = y[i]-'A', xt = x[i]-'A';
                    int kt = i%m;
                    if(k[kt]==-1) {
                        if(xt<=yt) k[kt]=yt-xt;
                        else k[kt]=26-xt+yt;
                    }
                    else {
                        m--;
                        if(m==0)
                            break;
                        i=-1;
                        memset(k, -1, len);
                    }
                }
            }

            if(m==0)
                break;

            //Find missing
            for(int i=0;i<len;i++)
            {
                int kt = i%m;
                if(k[kt]!=-1 && found[i]!=-1 && x[i]=='*' && y[i]!='*')
                {
                    int yt = y[i]-'A';
                    if(k[kt]<=yt) found[i]=yt-k[kt]+'A';
                    else found[i]=91-k[kt]+yt;
                } else found[i]=-1;
            }
        } while(--m);

        for(int i=0;i<len;i++)
        {
            if(x[i]!='*' && found[i]==-1)
                printf("%c", x[i]);
            else if(found[i]!=-1)
                printf("%c", found[i]);
            else if(x[i]!=0)
                printf("*");
        }
        printf("\n");
    }
}
