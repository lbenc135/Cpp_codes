#include <cstdio>
using namespace std;

int main()
{
    int a, b, rj=0;
    scanf("%i %i", &a, &b);
    while(true)
    {
        if(b%2) rj+=a;
        if(b<2) break;
        a+=a;
        b/=2;
    }
    printf("%i\n", rj);
}
