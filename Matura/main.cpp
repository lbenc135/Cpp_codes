#include <cstdio>
using namespace std;

int main()
{
    int s, m, d, si, mi;
    scanf("%i %i %i", &s, &m, &d);
    int mp=s*60+m;
    int mk=mp+d;
    for(int i=0;i<3;i++)
    {
        scanf("%i %i", &si, &mi);
        int im=si*60+mi;
        if(im-mp<30 || mk-im<=15) printf("NE\n");
        else printf("DA\n");
    }
}
