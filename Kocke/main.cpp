#include <cstdio>
using namespace std;

struct kocka
{
    int gore=3, dolje=4, lijevo=5, desno=2, napred=1, iza=6;
} kocke[2];

void up(int k)
{
    int t=kocke[k].gore;
    kocke[k].gore=kocke[k].napred;
    kocke[k].napred=kocke[k].dolje;
    kocke[k].dolje=kocke[k].iza;
    kocke[k].iza=t;
}

void down(int k)
{
    int t=kocke[k].gore;
    kocke[k].gore=kocke[k].iza;
    kocke[k].iza=kocke[k].dolje;
    kocke[k].dolje=kocke[k].napred;
    kocke[k].napred=t;
}

void right(int k)
{
    int t=kocke[k].gore;
    kocke[k].gore=kocke[k].lijevo;
    kocke[k].lijevo=kocke[k].dolje;
    kocke[k].dolje=kocke[k].desno;
    kocke[k].desno=t;
}

void left(int k)
{
    int t=kocke[k].gore;
    kocke[k].gore=kocke[k].desno;
    kocke[k].desno=kocke[k].dolje;
    kocke[k].dolje=kocke[k].lijevo;
    kocke[k].lijevo=t;
}

void zovi(char s, int k)
{
    switch(s)
    {
    case 'U':
        up(k);
        break;
    case 'D':
        down(k);
        break;
    case 'R':
        right(k);
        break;
    case 'L':
        left(k);
        break;
    default:
        break;
    }
}

int main()
{
    int n;
    char m[101], s[101];
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf(" %c", &m[i]);
    for(int i=0;i<n;i++)
        scanf(" %c", &s[i]);

    int rez=0;
    for(int i=0;i<n;i++)
    {
        zovi(m[i], 0);
        zovi(s[i], 1);

        if(kocke[0].gore==kocke[1].gore) rez++;
    }

    printf("%i\n", rez);
}
