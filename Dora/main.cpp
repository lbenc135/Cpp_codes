#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int x, p, y;
    scanf("%i %i %i", &x, &p, &y);
    printf("%i", max(0, p-(x+y-1)/y));
}
