#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    if(n-m-1<0) printf("0\n");
    else printf("%i\n", n-m-1);
}
