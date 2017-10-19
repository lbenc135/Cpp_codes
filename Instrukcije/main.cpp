#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> niz;
    niz.push_back(0);
    for(int i=1;i<50;i++)
        for(int j=0;j<i;j++)
            niz.push_back(i);

    int a, b, rez=0;
    cin >> a >> b;

    for(int i=a;i<=b;i++)
        rez+=niz[i];

    cout << rez;
}
