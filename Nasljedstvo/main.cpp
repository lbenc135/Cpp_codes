#include <iostream>
using namespace std;

int main()
{
    int n, o;
    cin >> n >> o;
    int maxi=o/(1.0-1.0/n);
    int mini=maxi;
    if(o%(n-1)==0) mini--;
    cout << mini << " " << maxi;
}
