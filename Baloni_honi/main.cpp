#include <iostream>
using namespace std;

#define MAXN 1000001

int n, h[MAXN];
bool naj[MAXN];
int br;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> h[i];

    for(int i=0;i<n;i++)
    {
        if(naj[h[i]+1])
            naj[h[i]+1]=0;
        else
            br++;
        naj[h[i]]=1;
    }

    cout << br;
}
