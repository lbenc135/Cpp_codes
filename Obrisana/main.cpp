#include <cstdio>
using namespace std;

int main()
{
    char zn[10]={0};
    int z;
    for(int i=0;i<7;i++)
    {
        scanf("%i", &z);
        zn[z]++;
    }
    for(int i=0;i<10;i++)
        if(zn[i]==1) {
            printf("%i", i);
            break;
        }
}
