#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int piramida[n][n];
    int maks[n][n], maxi=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin >> piramida[i][j];

    maks[0][0]=piramida[0][0];
    for(int i=1;i<n;i++)
        for(int j=0;j<=i;j++)
        {
            if(j==0) maks[i][j]=maks[i-1][j]+piramida[i][j];
            else if(j==i) maks[i][j]=maks[i-1][j-1]+piramida[i][j];
            else maks[i][j]=max(maks[i-1][j], maks[i-1][j-1])+piramida[i][j];
        }
    for(int i=0;i<n;i++)
        if(maks[n-1][i]>maxi) maxi=maks[n-1][i];

    cout << maxi;
}
