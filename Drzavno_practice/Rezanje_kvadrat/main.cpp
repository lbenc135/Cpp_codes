#include <cstdio>
using namespace std;

int stanje[100][100];

int sqrcut(int r, int s)
{
    if(r==s) return 0;
    if(r<s)
    {
        return sqrcut(r, s-r)+1;
    }
    else
    {
        return sqrcut(r-s, s)+1;
    }
}

int main()
{
    int r, s;
    scanf("%i %i", &r, &s);
    printf("%i\n", sqrcut(r, s));
}
