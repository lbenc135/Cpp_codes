#include <iostream>
#include <string>
using namespace std;

int main()
{
    int r, s, k;
    string rs;
    int eaten[3];
    cin >> r >> s;
    for(int i=0;i<3;i++)
    {
        cin >> k;
        cin >> rs;
        if(rs=="stupaca")
        {
            eaten[i] = r*k;
            s-=k;
        }
        if(rs=="redova")
        {
            eaten[i] = s*k;
            r-=k;
        }
    }

    cout << eaten[0] << endl;
    cout << eaten[1] << endl;
    cout << eaten[2];
}
