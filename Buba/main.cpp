#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, h, minp=1000000, nacina=1, pr;
    cin >> n >> h;
    n/=2;
    int stalagmiti[n], stalaktiti[n];
    for(int i=0;i<n;i++)
        cin >> stalagmiti[i] >> stalaktiti[i];

    sort(stalagmiti, stalagmiti+n);
    sort(stalaktiti, stalaktiti+n);

    for(int i=0;i<h;i++)
    {
        pr=n-(int)(lower_bound(stalagmiti, stalagmiti+n, i+1)-stalagmiti) + n-(int)(lower_bound(stalaktiti, stalaktiti+n, h-i)-stalaktiti);
        if(pr<minp) {minp=pr; nacina=1;}
        else if(pr==minp) nacina++;
    }

    cout << minp << " " << nacina;
}
