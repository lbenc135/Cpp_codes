#include <cstdio>
using namespace std;

int abs(int x);

int main()
{
    int g[10], a=0;
    bool can=true;
    for(int i=0;i<10;i++)
    {
        scanf("%i", &g[i]);
        if(abs(100-a)>=abs(100-a-g[i]) && can)
            a+=g[i];
        else
            can=false;
    }
    printf("%i", a);
}

int abs(int x)
{
    return x<0?-x:x;
}
