#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    char polje[502][502];
    int s=5*n+1, v=5*m+1;
    for(int i=0;i<v;i++)
        for(int j=0;j<s;j++)
            cin >> polje[i][j];

    int prozori[5]={0};
    for(int i=1;i<v;i+=5)
    {
        for(int j=1;j<s;j+=5)
        {
            int h=0, d=i;
            while(polje[d][j]=='*')
            {
                h++;
                d++;
            }
            prozori[h]++;
        }
    }
    for(int i=0;i<5;i++)
        cout << prozori[i] << " ";
}
