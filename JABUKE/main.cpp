#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m, j, result=0, low, high;
    cin >> n >> m >> j;
    int jab[j];
    low=1; high=m;
    for(int i=0;i<j;i++)
    {
        cin >> jab[i];
        if(abs(high-jab[i]) < abs(low-jab[i])) {result += abs(high-jab[i]); high = jab[i]; low=high-m+1;}
        else {result += abs(low-jab[i]); low = jab[i]; high=low+m-1;}
    }
    cout << result;
}
