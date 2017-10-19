#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int c, d;
    scanf("%i %i", &c, &d);
    int b, r;
    b = 2+c/2;
    r = c+d;
    int d1 = (b+sqrt(b*b-4*r))/2;
    printf("%i %i\n", d1, r/d1);
}
