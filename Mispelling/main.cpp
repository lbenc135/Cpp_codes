#include <iostream>
using namespace std;

int main()
{
    short t;
    cin >> t;
    for(int c=0;c<t;c++)
    {
        short m;
        cin >> m;
        m--;
        string w;
        cin >> w;
        short len = w.length();
        cout << c+1 << " ";
        for(int i=0;i<len;i++)
        {
            if(i!=m)
                cout << w[i];
        }
        cout << endl;
    }
}
