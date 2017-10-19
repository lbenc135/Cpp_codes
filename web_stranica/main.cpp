#include <iostream>
using namespace std;

int main()
{
    int n, p, k;
    cin >> n >> p >> k;
    int pt=p-k-2;
    while(1)
    {
        pt++;
        if(p-k>1 && pt==p-k-1) {cout << "<< "; continue;}
        if(pt==p) cout << "(" << p << ") ";
        else if(p+k<n && pt==p+k+1) {cout << ">>"; break;}
        else if(pt>n) break;
        else if(pt<1) continue;
        else cout << pt << ' ';
    }
}
