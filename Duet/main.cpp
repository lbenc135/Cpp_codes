#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n1, n2, n3, n4;
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
    printf("%i\n", min(n1, 12-n1)+min(n2, 12-n2)+min(n3, 12-n3)+min(n4, 12-n4));
}
