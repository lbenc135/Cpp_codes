#include <cstdio>
using namespace std;

bool opcenito(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int orent1=(y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
    int orent2=(y4-y2)*(x2-x1)-(y2-y1)*(x4-x2);
    int orent3=(y1-y4)*(x4-x3)-(y4-y3)*(x1-x4);
    int orent4=(y2-y4)*(x4-x3)-(y4-y3)*(x2-x4);

    if(orent1==0) orent1=-orent2;
    if(orent2==0) orent2=-orent1;
    if(orent3==0) orent3=-orent4;
    if(orent4==0) orent4=-orent3;

    bool r12=0, r34=0;
    if(orent1<0 && orent2>0 || orent1>0 && orent2<0)
        r12=1;
    if(orent3<0 && orent4>0 || orent3>0 && orent4<0)
        r34=1;
    if(r12 && r34) return true;

    return false;
}

int main()
{
    int x1, x2, y1, y2, x3, x4, y3, y4;
    scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
    scanf("%i %i %i %i", &x3, &y3, &x4, &y4);

    if(opcenito(x1, y1, x2, y2, x3, x4, y3, y4)) printf("Sjeku se\n");
    else printf("Ne sjeku se\n");
}
