#include <cstdio>
using namespace std;

int d[][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        unsigned a, b;
        scanf("%u %u", &a, &b);
        if(b==0) printf("1\n");
        else printf("%i\n", d[a%10][--b%4]);
    }
}
