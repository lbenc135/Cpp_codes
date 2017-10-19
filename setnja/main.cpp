#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];

    int a=0, b=0;
    for(int i=0;i<n;i++)
    {
        a+=x[i];
        b+=y[i];
    }
    cout << a << " " << b << endl;

    double min=1000000, temp;
    for(int i=0;i<n;i++)
    {
        a=b=0;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            a+=x[j];
            b+=y[j];
        }
        temp=sqrt(a*a + b*b);
        if(temp<min) min=temp;
    }
    printf("%.2lf", min);
}
