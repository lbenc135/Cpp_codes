#include <cstdio>
#include <cstring>
using namespace std;

bool isPalindrom(char a[], int len);

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        char a[1000001];
        scanf("%s", &a);
        int len = strlen(a), dalje=0, it=0, pt1, pt2;
        bool needToInc = true, needlast1=false;
        do
        {
            pt1 = len/2+it;
            pt2 = (len-1)/2-it;
            if(a[pt1]<a[pt2]) {
                needToInc=false;
                break;
            }
            it++;
        } while(a[pt1]==a[pt2] && pt2>0);
        it=0;
        if(needToInc)
            do
            {
                int half = (len-1)/2-it;
                if(half>=0)
                {
                    a[half]++;
                    if(a[half]>'9')
                    {
                        a[half]='0';
                        it++;
                        dalje=1;
                    } else dalje=0;
                } else {
                    dalje=0;
                    printf("1");
                    needlast1=true;
                }

            } while(dalje);
        for(int i=0;i<len/2;i++)
            printf("%c", a[i]);
        if(len%2 && !(a[len/2]=='0' && len==1))
            printf("%c", a[len/2]);
        for(int i=len/2-1;i>=0+needlast1;i--)
            printf("%c", a[i]);
        if(needlast1)
            printf("1");
        printf("\n");
    }
}

bool isPalindrom(char a[], int len)
{
    int half = len/2;
    for(int i=0;i<half;i++)
        if(a[i]!=a[len-1-i])
            return false;
    return true;
}
