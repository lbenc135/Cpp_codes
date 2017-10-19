#include <iostream>
using namespace std;

int brute(int x, int y, int n);

int matrica[401][401]={0};

int main()
{
    int n, maxi=0, temp;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> matrica[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            temp = brute(i, j, n);
            if(temp>maxi) maxi = temp;
        }
    cout << maxi;
}

int brute(int x, int y, int n)
{
    int maxi=0, a, b;
    for(int i=1;i<n-max(x, y);i++)
    {
        a=0; b=0;
        for(int j=0;j<=i;j++)
        {
            a += matrica[x+j][y+j];
            b += matrica[x+j][i-j+y];
        }
        if(a-b > maxi) maxi = a-b;
    }
    return maxi;
}
