#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    long long rez=0;
    for(int i=1;i<=a;i++)
        for(int j=i;j<=a;j++)
            if(i*j<=a) rez++;
            else break;
    cout << rez;
}
