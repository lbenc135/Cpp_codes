#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a-b)<n%max(a,b)+min(a,b))
    {
        cout << abs(a-b) << endl;
        if(a>b) cout << "CW";
        else cout << "CCW";
    }
    else
    {
        cout << n%max(a,b)+min(a,b) << endl;
        if(a>b) cout << "CCW";
        else cout << "CW";
    }
}
