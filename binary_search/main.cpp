#include <iostream>
#include <algorithm>
using namespace std;

int bin_s(int polje[], int s, int br);

int main()
{
    int n;
    cin >> n;
    int polje[n];
    for(int i=0;i<n;i++)
        cin >> polje[i];
    int br;
    cin >> br;

    cout << bin_s(polje, n, br)+1;
}

inline int bin_s(int polje[], int s, int br)
{
    sort(polje, polje+s);
    int minv=0, maxv=s;
    int mid;
    while(1)
    {
        mid =(minv+maxv)/2;
        if(polje[mid]<br) minv=mid;
        else if(polje[mid]>br) maxv=mid;
        else if(polje[mid]==br) return mid;
        if(minv==maxv-1) return -2;
    }
}
