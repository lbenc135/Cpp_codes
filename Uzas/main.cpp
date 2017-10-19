#include <cstdio>
using namespace std;

int main()
{
    int x, y, br=0;
    scanf("%i %i", &x, &y);
    if(x%2) printf("0\n");
    else
    {
        if(x>y)
        {
            x^=y;
            y^=x;
            x^=y;
        }
        for(int i=x;i<=y;i+=2)
            if(i%4==0) br++;
        printf("%i\n", br);
    }
}
