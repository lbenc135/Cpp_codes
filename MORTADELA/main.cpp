#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int xd, yd;
    cin >> xd >> yd;
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];

    double minc=10000000, temp;
    for(int i=0;i<n;i++)
    {
        temp = (1000.0/y[i])*x[i];
        if(temp<minc) minc = temp;
    }
    printf("%.2lf", minc);
}
