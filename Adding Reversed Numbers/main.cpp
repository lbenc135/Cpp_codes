#include <iostream>
using namespace std;

int Reverse(int);

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin >> a >> b;
        a = Reverse(a);
        b = Reverse(b);
        cout << Reverse(a+b) << endl;
    }
}

int Reverse(int x)
{
    int y=0;
    while(x>0)
    {
        y=(y*10)+(x%10);
        x/=10;
    }
    return y;
}
