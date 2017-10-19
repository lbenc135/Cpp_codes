#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int djeca[n];
    for(int i=0;i<n;i++)
        cin >> djeca[i];

    int pt=1;
    for(int i=0;i<x;i++)
    {
        cout << djeca[pt-1] << " ";
        pt=djeca[pt-1];
    }
}
