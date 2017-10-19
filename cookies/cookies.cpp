#include <iostream>
using namespace std;

int main()
{
    int temp;
    int kutija;
    int cookies;
    int res;
    for(int t=0;t<3;t++)
    {
        cin >> kutija;
        temp=0;
        res=0;
        for(int i=0;i<kutija;i++)
        {
            cin >> cookies;
            if(cookies==1)
            {
                res=-1;
            }
            if (cookies % 2 != 0)
            {
                temp++;
            }
        }
        if(temp % 2 != 0 || res==-1)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
}
