#include <iostream>
using namespace std;

int main()
{
    int sum, n;
    cin >> sum >> n;
    int novci[n];
    for(int i=0;i<n;i++)
        cin >> novci[i];

    int stanje[sum+1];
    for(int i=0;i<=sum;i++)
        stanje[i]=1000000;
    stanje[0]=0; stanje[novci[0]]=1;
    for(int i=novci[0]*2;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
            if(i-novci[j]>=0)
                stanje[i]=min(stanje[i], stanje[i-novci[j]]+1);
    }

    cout << stanje[sum];
}
