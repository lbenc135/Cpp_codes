#include <iostream>
using namespace std;

int main()
{
    float a,b,c,i,j,k;
    float maxn,maxo;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> i;
    cin >> j;
    cin >> k;
    maxo=i;
    if(j>maxo)
        maxo=j;
    if(k>maxo)
        maxo=k;
    maxn=a;
    if(maxo==j)
        maxn=b;
    if(maxo==k)
        maxn=c;
    a-=(i/maxo)*maxn;
    b-=(j/maxo)*maxn;
    c-=(k/maxo)*maxn;
    cout << (int)a << " " << (int)b <<" " << (int)c << endl;
}
