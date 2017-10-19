#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,temp,t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        long diff=1000000000;
        cin >> n >> k;
        long h[n];
        for(int j=0;j<n;j++)
            cin >> h[j];
        sort(h,h+n);

        for(int j=0;j<=n-k;j++)
        {
            temp=h[j+k-1]-h[j];
            if(temp<diff) diff = temp;
        }
        cout << diff << endl;
    }
}
