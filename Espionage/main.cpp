#include <iostream>
using namespace std;

int main()
{
    int t,n,r;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        bool spied=false;
        int spies[1000]={0};
        int civs[1000]={0};

        cin >> n >> r;
        for(int j=0;j<r;j++)
        {
            cin >> spies[j];
            cin >> civs[j];
        }


        for(int k=0;k<r;k++)
        {
            for(int l=0;l<r;l++)
            {
                if(spies[l]==civs[k]) spied=true;
            }
        }
        if(spied==false) cout << "Scenario #" << i+1 << ": spying" << endl;
        else cout << "Scenario #" << i+1 << ": spied" << endl;
    }
}
