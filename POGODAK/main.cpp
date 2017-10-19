#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (int)log2(b-a+1)+1;
}
