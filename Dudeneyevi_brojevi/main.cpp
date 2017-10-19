#include <iostream>
using namespace std;

int main()
{
    int n, temp, zbroj=0;
    cin >> n;
    temp=n;
    for(int i=0;temp>0;i++)
    {
        zbroj+=temp%10;
        temp/=10;
    }
    if(zbroj*zbroj*zbroj == n) cout << "Dudeneyev";
    else cout << "nije Dudeneyev";
}
