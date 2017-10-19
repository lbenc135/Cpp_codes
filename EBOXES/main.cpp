#include <cstdio>
using namespace std;

int main()
{
    int c,n,k,t,f;;
    scanf("%i", &c);
    while(c--)
    {
        scanf("%i %i %i %i", &n, &k, &t, &f);
        printf("%i\n", f+(f-n)/--k);
    }
}
