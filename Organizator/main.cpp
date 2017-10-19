#include <cstdio>
using namespace std;

int t[2000001];

int main()
{
    int n;
    scanf("%i", &n);
    int k, maxv=0;
    for(int i=0;i<n;i++)
    {
        scanf("%i", &k);
        if(k>maxv) maxv=k;
        t[k]++;
    }
    long long rez=n, temp;
    int g;
    for(int i=1;i<=maxv;i++)
    {
        temp=0; g=0;
        for(int j=i;j<=maxv;j+=i)
                temp+=t[j];
        if(temp*i>rez && temp>1) rez=temp*i;
    }

    printf("%i", rez);
}
