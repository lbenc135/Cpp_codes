#include <iostream>
using namespace std;

int l;

string okreni(string a)
{
    string rez;
    for(int i=0;i<l;i+=2)
        rez.push_back(a[i]);
    l--;
    for(int i=l-!(l%2);i>0;i-=2)
        rez.push_back(a[i]);
    l++;
    return rez;
}

int findLoop(string a)
{
    string rez=okreni(a);
    int r=1;
    while(rez!=a)
    {
        rez=okreni(rez);
        r++;
    }
    return r;
}

int main()
{
    int x;
    string a;
    cin >> x >> a;
    l=a.length();
    x=x%findLoop(a);
    for(int i=0;i<x;i++)
        a=okreni(a);
    cout << a;
}
