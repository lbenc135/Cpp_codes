#include <iostream>
using namespace std;

int main()
{
    int t;
    string p, q;
    cin >> t;
    for(int c=0;c<t;c++)
    {
        cin >> p >> q;
        int line = 0, len = p.length(), l=0, mid;
        int h = len;
        while(l<h) {
            mid = (h+l)/2;
            if(q.find(p.substr(0, mid))!=string::npos)
                l=mid+1;
            else
                h=mid;
        }
        string leftq = q.substr(0, len-l+1), leftp = p.substr(l-1, len);
        if(leftq==leftp)
            cout << "Si\n";
        else cout << "No\n";
    }
}
