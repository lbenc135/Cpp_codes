#include <cstdio>

using namespace std;

int main()
{
    char ploca[8][8] {
    'Z','Z','Z','Z','Z','Z','Z','C',
    'P','P','P','P','P','P','Z','C',
    'P','L','L','L','L','P','Z','C',
    'Z','L','C','C','L','P','Z','C',
    'P','L','C','Z','P','P','Z','C',
    'P','L','C','Z','Z','Z','Z','C',
    'P','L','C','C','C','C','C','C',
    'P','L','L','L','L','L','L','L'
    };

    int r, s;
    scanf("%i %i", &r, &s);
    r--; s--;
    if(ploca[r][s]=='L')
        printf("ZELENA");
    else if(ploca[r][s]=='Z')
        printf("ZUTA");
    else if(ploca[r][s]=='C')
        printf("CRVENA");
    else if(ploca[r][s]=='P')
        printf("PLAVA");
}
