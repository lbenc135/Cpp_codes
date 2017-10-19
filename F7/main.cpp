#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) { return x > y; }

int main()
{
    int n, result=0, maks=0;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++)
        cin >> b[i];
    sort(b,b+n,cmp);

    for(int i=0;i<n;i++)
    {
        if(b[i]+n>=maks) result++;
        if(b[i]+i+1>maks) maks=b[i]+i+1;
    }

    cout << result;
}
