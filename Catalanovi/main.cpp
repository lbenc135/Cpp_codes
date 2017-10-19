#include <cstdio>
using namespace std;

long long stanje[1000];

long long catalan(int n)
{
    if(n<=1) return 1;
    if(stanje[n]!=0) return stanje[n];

    long long rez=0;
    for(int i=0;i<n;i++)
        rez+=catalan(i)*catalan(n-i-1);
    return stanje[n]=rez;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%lli", catalan(n));
}
