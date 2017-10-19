#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int p, s, m;
    m=s=n/3;
    p=n-2*m;
    printf("%i %i %i", p, s, m);
}
