#include <iostream>
using namespace std;

string kaliopa(string a)
{
    if(a.length()==1)
        return a;

    string a1 = kaliopa(a.substr(0, a.length()/2));
    string a2 = kaliopa(a.substr(a.length()/2, a.length()));
    return a1+a1+a2;
}

int main()
{
    string a;
    cin >> a;
    cout << kaliopa(a);
}
