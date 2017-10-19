#include <cstdio>
#include <cstring>
using namespace std;

#define ull unsigned long long

ull stanje[1000000];

ull exchange(ull n)
{
    if(n<1000000 && stanje[n])
        return stanje[n];
    if(n)
    {
        ull div=exchange(n/2)+exchange(n/3)+exchange(n/4);
        if(n>div)
        {
            if(n<1000000) stanje[n]=n;
            return n;
        }
        else
        {
            if(n<1000000) stanje[n]=div;
            return div;
        }
    }
    return 0;
}

int main()
{
    int n;
    while(scanf("%i", &n)>0)
    {
        printf("%llu\n", exchange(n));
    }
}
