#include <cstdio>
using namespace std;

int main()
{
    int t, n, a, d;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i %i %i", &n, &a, &d);
        printf("%i\n", n*a+n*(n-1)/2*d);
    }
}
