#include <iostream>
using namespace std;

int knapsack(int cc);

int n;
int maxv[100];
int w[100], v[100];

int main()
{
    int cc;
    cin >> cc >> n;
    for(int i=0;i<n;i++)
        cin >> w[i] >> v[i];

    cout << knapsack(cc);
}

int knapsack(int cc)
{
    if(maxv[cc]!=0) return maxv[cc];
    for(int i=0;i<n;i++)
    {
        if(cc-w[i]>=0 && knapsack(cc-w[i])+v[i]>maxv[cc])
            maxv[cc]=knapsack(cc-w[i])+v[i];
    }
    return maxv[cc];
}
