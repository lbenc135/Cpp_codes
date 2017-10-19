#include <iostream>
#include <graphics.h>
using namespace std;

#define col(r,g,b)   (0x04000000 | RGB(r,g,b))

double min(double a, double b)
{
    return a<b?a:b;
}

void unblur()
{
    for(int i=0;i<600;i++)
        for(int j=0;j<600;j++)
        {
            int px=getpixel(i, j);
            int r = px & 0xff;
            int g = (px >> 8) & 0xff;
            int b = (px >> 16) & 0xff;
            r=min(255, 127+(r-127)*4); r=r<0?0:r;
            g=min(255, 127+(g-127)*4); g=g<0?0:g;
            b=min(255, 127+(b-127)*4); b=b<0?0:b;
            putpixel(i, j, col(r,g,b));
        }
}

int main()
{
    initwindow(600, 600);

    for(int i=0;i<=35;i++)
    {
        putpixel(100+i, 100, col(i*7, 30, 30));
        putpixel(100+i, 101, col(i*7, 30, 30));
    }

    for(int i=0;i<100;i++)
    {
        putpixel(136+i, 100, col(255, 30, 30));
        putpixel(136+i, 101, col(255, 30, 30));
    }

    for(int i=0;i<=35;i++)
    {
        putpixel(236+i, 100, col(255-i*7, 30, 30));
        putpixel(236+i, 101, col(255-i*7, 30, 30));
    }

    delay(1000);
    unblur();

    while(!kbhit()) ;
    closegraph();
}
