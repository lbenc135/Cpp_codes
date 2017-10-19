#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int l, h, m;
    char res[5];
    scanf("%i %i", &l, &h);
    while(l<h)
    {
        m=(l+h)/2;
        printf("%i\n", m);
        fflush(stdout);
        scanf("%s", &res);
        if(!strcmp(res, "HIGH"))
            h=m;
        else if(!strcmp(res, "LOW"))
            l=m+1;
        else
            break;
    }
    return 0;
}
