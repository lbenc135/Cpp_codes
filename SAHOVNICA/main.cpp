#include <iostream>
using namespace std;

int main()
{
    int r, s, a, b;
    cin >> r >> s >> a >> b;
    for(int i=0;i<r*a;i++)
    {
        for(int j=0;j<s*b;j++)
        {
            if((i/a+j/b)%2==0) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
}
