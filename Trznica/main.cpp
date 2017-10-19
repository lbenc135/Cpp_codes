#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%i %i %i %i", &a, &b, &c, &d);
    printf("%i", min(a+d, b+c));
}
