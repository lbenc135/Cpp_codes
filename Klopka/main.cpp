#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[21], y[21];
    int l=1000, t=0, b=1000, r=0;
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        if(x[i]<l) l=x[i];
        if(x[i]>r) r=x[i];
        if(y[i]<b) b=y[i];
        if(y[i]>t) t=y[i];
    }
    if((t-b)>(r-l))
        cout << (t-b)*(t-b);
    else
        cout << (r-l)*(r-l);
}
