#include <iostream>
using namespace std;

int main()
{
    int bn, n;
    cin >> bn >> n;

    if(bn<10000) cout << bn*n;
    else cout << bn*n*2;
}
