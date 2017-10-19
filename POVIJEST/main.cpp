#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int uc[3];

    if(a==c && b==d || a==d && b==c) {cout << "SVI"; return 0;}

    if(a==c || b==c) {uc[0]=a; uc[1]=b; uc[2]=d;}
    else if (a==d || b==d) {uc[0]=a; uc[1]=b; uc[2]=c;}
    sort(uc, uc+3);

    cout << uc[0] << " " << uc[1] << " " <<  uc[2];
}
