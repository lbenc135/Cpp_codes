#include <cstdio>
#include <graphics.h>
#include <cmath>
using namespace std;

#define PI 3.1415

void rek(int x, int y, int x1, int y1, int kut)
{
    double a=sqrt(pow(x1-x,2)+pow(y1-y,2));

    if(a<10) return;

    int x2=x+cos(PI*kut/180)*a;
    int y2=y-sin(PI*kut/180)*a;
    int x3=x-sin(PI*kut/180)*a;
    int y3=y-cos(PI*kut/180)*a;
    int x4=x2-sin(PI*kut/180)*a;
    int y4=y2-cos(PI*kut/180)*a;

    int x5=(x3+x4)/2-sin(PI*kut/180)*(a/2);
    int y5=(y3+y4)/2-cos(PI*kut/180)*(a/2);


    line(x, y, x2, y2);
    line(x, y, x3, y3);
    line(x4, y4, x3, y3);
    line(x4, y4, x2, y2);

    line(x3, y3, x5, y5);
    line(x4, y4, x5, y5);


    rek(x3, y3, x5, y5, kut+45);
    rek(x5, y5, x4, y4, kut-45);
}

int main()
{
    initwindow(800, 800);

    rek(400, 600, 500, 600, 0);

    while(!kbhit());
    closegraph();
}
