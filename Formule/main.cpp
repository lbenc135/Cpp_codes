#include <iostream>
using namespace std;

int min_element(float arr[], int);

int main()
{
    int n,l;
    cin >> n >> l;
    int v[n], stupaca=4*n+1;
    float t[n];
    for(int i=0;i<n;i++)
        cin >> v[i];
    char polje[l][stupaca];
    for(int i=0;i<l;i++)
        for(int j=0;j<stupaca;j++)
            cin >> polje[i][j];

    int ptr=0, pts=3;
    for(int i=0;i<n;i++)
    {
        while(polje[ptr][pts]!='o')
        {
            ptr++;
        }
        t[i]=(float)(l-ptr)/v[i];
        pts+=4;
        ptr=0;
    }

    int najm;
    for(int i=0;i<n;i++)
    {
        najm=min_element(t, n);
        cout << najm+1 << " ";
        t[najm]=101;
    }
}

int min_element(float arr[], int n)
{
    int m=101;
    int it;
    for(int i=0;i<n;i++)
        if(arr[i]<m) {m = arr[i];it=i;}
    return it;
}
