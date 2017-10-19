#include <iostream>
using namespace std;

int calc_num(int a, int b)
{
    if(a<=1) return 1;
    if(b==1) return a;

    int zbr=0;
    for(int i=0;i<=b;i++)
        if(a!=2 && i!=0 || a==2 && i==0)
        zbr+=calc_num(a-1, b-i);

    return zbr;
}

int main()
{
    cout << calc_num(5, 5);
}
