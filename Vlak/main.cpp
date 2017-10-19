#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    switch(a)
    {
    case 1:
    case 2:
        cout << 8;
        break;
    case 3:
    case 4:
        cout << 5;
        break;
    case 5:
    case 6:
        cout << 4;
        break;
    case 7:
    case 8:
        cout << 1;
    }
    return 0;
}
