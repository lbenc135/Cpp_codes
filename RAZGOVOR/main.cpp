#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a*b%2==0) cout << abs(a-b)+1;
    else cout << abs(a-b)-1;
}
