#include <cstdio>
using namespace std;

int main()
{
    int r, s;
    scanf("%i %i", &r, &s);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
            printf("+-");
        printf("+\n");
        for(int j=0;j<s;j++)
            printf("|.");
        printf("|\n");
    }
    for(int j=0;j<s;j++)
        printf("+-");
    printf("+\n");
}
