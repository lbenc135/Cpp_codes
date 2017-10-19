#include <iostream>
using namespace std;

int main()
{
    int k[5], b[5], uk=0;
    for(int i=0;i<5;i++)
    {
      cin >> k[i] >> b[i];
      uk+=k[i]*b[i];
    }
    cout << uk;
}
