#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,s,result=0,boxes=0;
    cin >> n >> k >> s;
    int box[n];
    for(int i=0;i<n;i++)
    {
        cin >> box[i];
    }
    sort(box,box+n);

    for(int i=n-1;result<k*s;i--)
    {
        result+=box[i];
        boxes++;
    }
    cout << boxes << endl;
}
