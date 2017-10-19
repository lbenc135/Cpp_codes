#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int t, a, b, c;
    scanf("%i", &t);
    for(int d=1;d<=t;d++)
    {
        scanf("%i %i %i", &a, &b, &c);

        if(c%gcd(a, b)==0)
            printf("Case %i: Yes\n", d);
        else
            printf("Case %i: No\n", d);
    }
}
