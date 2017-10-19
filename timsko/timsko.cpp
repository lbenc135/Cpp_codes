#include <iostream>
using namespace std;

int main()
{
    int m,n,k, timova;
    cin >> m >> n >> k;

    while(m>2*n && k>0)
    {
        m--;
        k--;
    }
    while(m<2*n && k>0)
    {
        n--;
        k--;
    }
    if(k>0)
    {
        if(k%2==0)
        {
            m-=k/2;
            n-=k/2;
        }
        else
        {
            m-=k/2+1;
            n-=k/2;
        }
    }
    m/=2;
    if(n<m)
        timova=n;
    else
        timova=m;
    if(timova<0) timova=0;
    cout << timova << endl;
}
