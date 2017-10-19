#include <cstdio>
using namespace std;

int main()
{
    int t, n;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i", &n);
        if(n>2)
            printf("%i\n", n-2);
        else
            printf("0\n");
    }
}
