#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    int broj[n];
    int polje[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<n;i++)
    {
        cin >> broj[i];
        switch(broj[i])
        {
        case 1:
            temp=polje[0][0];
            polje[0][0]=polje[1][0];
            polje[1][0]=polje[1][1];
            polje[1][1]=polje[0][1];
            polje[0][1]=temp;
            break;
        case 2:
            temp=polje[0][1];
            polje[0][1]=polje[1][1];
            polje[1][1]=polje[1][2];
            polje[1][2]=polje[0][2];
            polje[0][2]=temp;
            break;
        case 3:
            temp=polje[1][0];
            polje[1][0]=polje[2][0];
            polje[2][0]=polje[2][1];
            polje[2][1]=polje[1][1];
            polje[1][1]=temp;
            break;
        case 4:
            temp=polje[1][1];
            polje[1][1]=polje[2][1];
            polje[2][1]=polje[2][2];
            polje[2][2]=polje[1][2];
            polje[1][2]=temp;
            break;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << polje[i][j];
        cout << endl;
    }

}
