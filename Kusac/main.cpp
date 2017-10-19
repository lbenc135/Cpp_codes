#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    double dio = (double)n/m;
    double cur=dio;
    int cuts=0;
    for(int i=0;i<m-1;i++)
    {
        double b = cur-(int)cur;
        if(b>0.001 && b<0.999)
            cuts++;
        cur+=dio;
    }
    printf("%i\n", cuts);
}
