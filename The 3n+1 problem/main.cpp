#include <iostream>
using namespace std;

int calcCycles(int x);

int main()
{
    int a,b;
    cin >> a >> b;
    int maxn=0;
    for(int i=a;i<=b;i++)
    {
        int cycles=calcCycles(i);
        if(cycles>maxn) maxn=cycles;
    }

    cout << a << " " << b << " " << maxn << endl;
}

int calcCycles(int x)
{
    int cycles=1;
    while(x!=1)
    {
        if(x%2==0) x/=2;
        else
        {
            x*=3;
            x++;
        }
        cycles++;
    }
    return cycles;
}
