#include <iostream>
using namespace std;

int main()
{
    char v, b;
    cin >> v >> b;
    int q;
    cin >> q;

    char pv, pb;
    for(int i=0;i<q;i++)
    {
        cin >> pv >> pb;
        if(pv==v) cout << 1;
        else cout << 0;
        if(pb==b) cout << 1;
        else cout << 0;
        cout << endl;
    }
}
