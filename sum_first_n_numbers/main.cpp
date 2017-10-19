#include <iostream>
using namespace std;

int main()
{
    int n, zbroj=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        zbroj+=i;
    cout << zbroj;
}
