#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    int b[n], p[m];
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int i=0;i<m;i++)
        cin >> p[i];
    sort(b, b+n);
    reverse(b, b+n);
    sort(p, p+m);
    reverse(p, p+m);

    int bicikli=0, novaca=0, temp=a;
    for(int i=0;i<m;i++)
    {
        if(a+b[i]>=p[i])
        {
            if(p[i]-b[i]>0) a-=p[i]-b[i];
            bicikli++;
        }
    }
    cout << bicikli << " ";
    for(int i=m-1;i>m-bicikli-1;i--)
        novaca+=p[i];

    cout << novaca-temp;
}
