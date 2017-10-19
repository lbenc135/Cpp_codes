#include <cstdio>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%i%i%i", &a, &b, &c);
    int maks=a+b+c;
    if(a*b+c>maks) maks=a*b+c;
    if(a*b*c>maks) maks=a*b*c;
    if(a+b*c>maks) maks=a+b*c;
    printf("%i\n", maks);
}
