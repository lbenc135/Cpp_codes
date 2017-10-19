#include <iostream>
using namespace std;

int n;
int p[10];

int pot(int a, int p)
{
    int b=1;
    for(int i=0;i<p;i++)
      b*=a;
    return b;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
      cin >> p[i];

    int x=0;
    for(int i=0;i<n;i++)
        x+=pot(p[i]/10, p[i]%10);

    cout << x;
}
