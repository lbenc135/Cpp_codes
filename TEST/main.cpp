#include <cstdio>
using namespace std;

int main()
{
    int a;
    while(true) {
        scanf("%i", &a);
        if(a==42)
            break;
        else
            printf("%i\n", a);
    }
}
