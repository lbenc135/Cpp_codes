#include <iostream>
using namespace std;

int main()
{
    string names[4];
    for(int i=0;i<4;i++)
        cin >> names[i];
    int n;
    cin >> n;
    string okrenuli[4];
    for(int i=0;i<n;i++)
        cin >> okrenuli[i];

    if(n==0) cout << "Jao\n";
    else
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(names[i]==okrenuli[j])
                {
                    cout << names[i] << endl;
                    return 0;
                }
            }
        }
    }
}
