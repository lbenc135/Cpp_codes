#include <iostream>
using namespace std;

int main()
{
    int x,y;
    for(int field=1;cin >> x >> y;field++)
    {
        if(x==0 && y==0) return 0;
        char polje[x][y];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                cin >> polje[i][j];

        int mines=0;

        cout << "Field #" << field << ":\n";
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(polje[i][j]=='*')
                {
                    cout << "*";
                    continue;
                }

                if(polje[i+1][j]=='*' && i<x-1) mines++;
                if(polje[i-1][j]=='*' && i>0) mines++;
                if(polje[i][j+1]=='*' && j<y-1) mines++;
                if(polje[i][j-1]=='*' && j>0) mines++;
                if(polje[i+1][j+1]=='*' && i<x-1 && j<y-1) mines++;
                if(polje[i-1][j-1]=='*' && i>0 && j>0) mines++;
                if(polje[i-1][j+1]=='*' && j<y-1 && i>0) mines++;
                if(polje[i+1][j-1]=='*' && j>0 && i<x-1) mines++;

                polje[i][j]=(int)mines;
                cout << mines;
                mines=0;
            }
            cout << endl;
        }
        cout << endl;
    }
}
