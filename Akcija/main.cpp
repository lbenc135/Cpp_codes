#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, c[100001];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> c[i];

    int br=0;
    sort(c, c+n, greater<int>());
    for(int i=0;i<n;i++)
        if(i%3!=2) br+=c[i];

    cout << br;
}
