#include <cstdio>
using namespace std;

int main()
{
    int g, b;
    while(1)
    {
        scanf("%i %i", &g, &b);
        if(g==b && b==-1) break;
        if(b>g)
        {
            b^=g;
            g^=b;
            b^=g;
        }
        printf("%i\n", (g+b)/(b+1));
    }
}
