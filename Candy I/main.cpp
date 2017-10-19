#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int t=0;
    cin >> t;
    do
    {

        int num[t],sum=0,moves=0;
        for(int i=0;i<t;i++)
        {
            cin >> num[i];
            sum+=num[i];
        }

        if(((float)sum/t)-sum/t>0) cout << -1 << endl;
        else
        {
            for(int i=0;i<t;i++)
            {
                moves+=abs(sum/t-num[i]);
            }
            cout << moves/2 << endl;
        }
        cin >> t;
    }while(t!=-1);
}
