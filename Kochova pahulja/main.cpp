#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.14

void rek(int x1, int y1, int x2, int y2, int kut)
{
    double a=sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));

    int x3=(x2-x1)/3+x1, y3=(y2-y1)/3+y1;
    int x5=(x2-x1)*2/3+x1, y5=(y2-y1)*2/3+y1;
    int x4=(x1+x2)/2-sin(PI*kut/180)*(a/3);
    int y4=(y1+y2)/2-cos(PI*kut/180)*(a/3);

    if(a<20)
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x4, y4);
        line(x4, y4, x5, y5);
        line(x5, y5, x2, y2);
        return;
    }

    rek(x1, y1, x3, y3, kut);
    rek(x5, y5, x2, y2, kut);
    rek(x3, y3, x4, y4, kut+60);
    rek(x4, y4, x5, y5, kut-60);
}

void koch_pahulja()
{
    rek(500, 400, 100, 400, 180);
    rek(100, 400, 300, 54,  60);
    rek(300, 54,  500, 400,-60);
}

void koch_anti()
{
    rek(100, 400, 500, 400, 0);
    rek(300, 54, 100, 400, 240);
    rek(500, 400, 300, 54, -240);
}

void ekst_pahulja()
{
    rek(500, 200, 200, 200, 180);
    rek(200, 200, 50, 400, 240);
    rek(650, 400, 500, 200, -240);
    rek(50, 400, 200, 600, -60);
    rek(500, 600, 650, 400, 60);
    rek(200, 600, 500, 600, 0);
}

void cesaro()
{
    rek(500, 200, 200, 200, 180);
    rek(200, 200, 200, 500, -90);
    rek(200, 500, 500, 500, 0);
    rek(500, 500, 500, 200, 90);
}

int main()
{
    initwindow(800, 800);

    cesaro();

    while(!kbhit());
    closegraph();
}
