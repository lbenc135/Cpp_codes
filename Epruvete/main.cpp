#include <iostream>
using namespace std;

int gcd(int a, int b) {return b?gcd(b, a%b):a;}

int main()
{
    int n, m;
    cin >> n;
    int r[n];
    int h[n];
    for(int i=0;i<n;i++)
        cin >> r[i] >> h[i];
    cin >> m;
    int x[n];
    int y[n];
    for(int i=0;i<m;i++)
        cin >> x[i] >> y[i];

    int V[n];
    for(int i=0;i<n;i++)
        V[i]=r[i]*r[i]*h[i];

    for(int i=0;i<m;i++)
    {
        V[y[i]-1]+=V[x[i]-1];
        V[x[i]-1]=0;
    }

    int visina;
    int r2;
    for(int i=0;i<n;i++)
    {
        r2=r[i]*r[i];
        visina=V[i]/r2;
        if(V[i]%r2==0) cout << visina << endl;
        else if(visina<1) {cout << V[i]/gcd(V[i], r2) << "/" << r2/gcd(V[i], r2) << endl;}
        else {cout << V[i]/r2 << " " << V[i]%r2/gcd(V[i]%r2, r2) << "/" << r2/gcd(V[i]%r2, r2) << endl;}
    }
}
