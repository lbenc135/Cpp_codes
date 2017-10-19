#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int umnozak=1, produzetak, produzetakA;

    if(a%10!=0)
        umnozak*=a%10;
    if((a%100)/10!=0)
        umnozak*=(a%100)/10;
    if(a/100!=0)
        umnozak*=a/100;

    produzetakA=a+umnozak;

    for(int i=1;i<=a;i++)
    {
        umnozak=1;
        if(i%10!=0)
            umnozak*=i%10;
        if((i%100)/10!=0)
            umnozak*=(i%100)/10;
        if(i/100!=0)
            umnozak*=i/100;

        produzetak=i+umnozak;
        if(produzetak+produzetakA==b) cout << i << " ";
    }

}
