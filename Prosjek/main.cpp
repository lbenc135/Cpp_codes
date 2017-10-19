#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[101], b[101];
    for(int i=0;i<n;i++)
        cin >> b[i];

    a[0]=b[0];
    int suma=a[0];
    cout << a[0] << " ";
    for(int i=1;i<n;i++)
    {
        a[i]=b[i]*(i+1)-suma;
        cout << a[i] << " ";
        suma+=a[i];
    }
}
