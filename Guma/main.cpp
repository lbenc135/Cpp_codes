#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a==0) return b;
    return gcd(b%a, a);
}

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    cin >> a[0];
    long long rez=a[0]-1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        rez+=a[i]-gcd(a[i], a[i-1]);
    }

    cout << rez;
}
