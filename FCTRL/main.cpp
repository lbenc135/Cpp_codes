#include <cstdio>
using namespace std;

int main()
{
    int t, n, rez;
    scanf("%i", &t);
    while(t--)
    {
        rez=0;
        scanf("%i", &n);
        for (int p = 5; p <= n; p*=5)
            rez += n/p;
        printf("%i\n", rez);
    }
}
