#include <cstdio>
using namespace std;

long long step[100000];

long long rek(int n)
{
    if(n<0) return 0;
    if(n==0 || n==1) return 1;
    if(step[n]) return step[n];

    return step[n]=rek(n-1)+rek(n-2)+rek(n-3);
}

int main()
{
    int n;
    scanf("%i", &n);

    printf("%lli\n", rek(n));
}
