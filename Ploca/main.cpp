#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    scanf("%i %i %i %i %i %i", &a, &b, &c, &d, &e, &f);
    int ukupno = (b+e+f)*a + (c+d)*e;
    printf("%i\n", ukupno);
    int temp = a%2==1?(e*d+1)/2:e*d/2;
    int bijelih = ((b+e+f)*a+1)/2 + (e*c+1)/2 + temp;
    printf("%i ", bijelih);
    printf("%i", ukupno-bijelih);
}
