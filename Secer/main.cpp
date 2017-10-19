#include <iostream>
using namespace std;

int main()
{
    int n, paketa=0;
    cin >> n;
    while(n%5!=0 && n!=0)
    {
        n-=3; paketa++;
        if(n<0) {cout << -1; return 0;}
    }
    paketa+=n/5;
    cout << paketa;
}
