#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    char s[51];
    scanf("%s", &s);

    int c=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='S') c++;
        else {
            c++;
            i++;
        }
    }

    printf("%i", c);
}
