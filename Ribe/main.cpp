#include <cstdio>
using namespace std;

int main()
{
    int n;
    int s[200001];
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i", &s[i]);

    int r=0;
    long long maxs=s[0];
    for(int i=0;i<n;i++)
    {
        if(maxs<s[i])
        {
            r++;
            maxs+=s[i];
        }
        printf("%i\n", r);
    }
}
