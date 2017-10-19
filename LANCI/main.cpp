#include <iostream>
#include <algorithm>
using namespace std;

int n;
int l[1000000];

int main()
{
    cin >> n;
    for( int i = 0; i < n; ++i )
        cin >> l[i];
    sort(l, l + n);

    int sol = 0;
    for(int i=0; sol < n-i-1; i++)
        sol += min(n-i-1-sol, l[i]);

    cout << sol;
}
