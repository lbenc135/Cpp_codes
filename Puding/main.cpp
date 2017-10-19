#include <cstdio>
using namespace std;

int main()
{
    int n, a, b, c, d, e;
    scanf("%i %i %i %i %i %i", &n, &a, &b, &c, &d, &e);

    if(n-(a+b+c)/2>=d/2) printf("PUDING OD COKOLADE\n");
    else printf("PUDING OD VANILIJE\n");
}
