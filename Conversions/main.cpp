#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        double n;
        scanf("%lf", &n);
        string u;
        cin >> u;
        if(u=="kg")
            printf("%i %.4lf lb\n", c+1, n*2.2046);
        else if(u=="lb")
            printf("%i %.4lf kg\n", c+1, n*0.4536);
        else if(u=="l")
            printf("%i %.4lf g\n", c+1, n*0.2642);
        else if(u=="g")
            printf("%i %.4lf l\n", c+1, n*3.7854);
    }
}
