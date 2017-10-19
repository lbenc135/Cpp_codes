#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a+b)%2==1 && (c+d)%2==0)
        cout << c << " " << d << endl << a << " " << b;
    else if((a+c)%2==1 && (b+d)%2==0)
        cout << b << " " << d << endl << a << " " << c;
    else if((a+d)%2==1 && (b+c)%2==0)
        cout << b << " " << c << endl << a << " " << d;
    else cout << "NE";
    return 0;
}
