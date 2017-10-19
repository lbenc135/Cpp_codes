#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool start=true;
    while(n>0)
    {
        if(start==true && n%10==0) {n/=10; continue;}
        cout << n%10;
        n/=10;
        start=false;
    }
}
