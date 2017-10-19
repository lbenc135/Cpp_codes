#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int v[2001];
int stanje[2001][2001];

int rek(int a, int b, int s)
{
    if(stanje[a][b]) return stanje[a][b];
    if(a==b) return v[a]*s;
    return stanje[a][b]=max(rek(a+1, b, s+1)+v[a]*s, rek(a, b-1, s+1)+v[b]*s);
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i", &v[i]);

    printf("%i\n", rek(0, n-1, 1));
}
