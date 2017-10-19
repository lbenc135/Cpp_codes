#include <iostream>
using namespace std;

int main()
{
    int j=0, nl=0, g=0, n;
    cin >> n;
    char com;
    int memorija[100][100]={0}, r, s, b;
    for(int i=0;i<n;i++)
    {
        cin >> com;
        if(com=='S')
        {
            cin >> r >> s >> b;
            memorija[r][s]=b+1;
        }
        else if(com=='L')
        {
            cin >> r >> s;
            if(memorija[r][s]==2) j++;
            else if(memorija[r][s]==1) nl++;
            else g++;
        }
        else
            for(int j=0;j<100;j++)
                for(int k=0;k<100;k++)
                    memorija[j][k]=0;
    }
    cout << nl << " " << j << " " << g;
}
