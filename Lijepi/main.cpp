#include <iostream>
using namespace std;

bool lijepi(int x);

int main()
{
    int n, q, rj;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> q;
    int qa[q], qb[q];
    for(int i=0;i<q;i++)
    {
        cin >> qa[i] >> qb[i];

        rj=0;
        qa[i]--; qb[i]--;
        for(int j=qa[i];j<=qb[i];j++)
        {
            for(int k=j+1;k<=qb[i];k++)
            {
                if(lijepi(a[j]+a[k])) rj++;
            }
        }
        cout << rj << endl;
    }

}

bool lijepi(int x)
{
    while(x>0)
    {
        if(x%10!=9 && x%10!=1) return false;
        x/=10;
    }
    return true;
}
