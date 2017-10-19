#include <cstdio>
using namespace std;

int main()
{
    int t, n, rez;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i", &n);
        rez=0;
        while(n>0)
        {
            if(n%2 && n!=1) n+=2;
            n/=2;
            rez++;
        }
        printf("%i\n", rez);
    }
}
