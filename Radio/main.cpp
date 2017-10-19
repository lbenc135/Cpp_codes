#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, n, minr;
    bool k=0;
    cin >> a >> b >> n;
    int frek[n];
    minr=abs(a-b);
    for(int i=0;i<n;i++)
    {
        cin >> frek[i];
        if(abs(b-frek[i])<minr) {minr=abs(b-frek[i]); k=1;}
    }
    cout << minr+k;
}
