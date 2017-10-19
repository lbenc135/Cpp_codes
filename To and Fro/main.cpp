#include <iostream>
using namespace std;

int main()
{
    int c;
    while(true)
    {
        cin >> c;
        if(c==0) break;
        string m;
        cin >> m;
        int rows = m.length()/c;
        char arr[rows][c];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i%2==0)
                    arr[i][j]=m[i*c+j];
                else
                    arr[i][c-j-1]=m[i*c+j];
            }
        }
        for(int i=0;i<c;i++)
            for(int j=0;j<rows;j++)
                cout << arr[j][i];
        cout << endl;
    }
}
