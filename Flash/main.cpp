#include <iostream>
#include <string>
using namespace std;

string poc, traz;
int m, k;

bool ima1(int b, int pc, int kr)
{
    for(int i=pc;i<kr;i++)
        if(traz[i]=='1' && poc[i]=='0') return true;
    return false;
}

void turn2one(int b, int pc, int kr)
{
    for(int i=pc;i<kr;i++)
        poc[i]='1';
}

int main()
{
    cin >> m >> k >> poc >> traz;

    int uk=0;
    for(int i=0;i<m;i++)
    {
        int pc=i*(k+1);
        int kr=pc+k;

        if(ima1(i, pc, kr))
        {
            turn2one(i, pc, kr);
            uk+=100;
        }
        for(int j=pc;j<kr;j++)
        {
            if(poc[j]=='1' && traz[j]=='0')
            {
                poc[j]='0';
                uk++;
            }
        }
    }
    cout << uk << endl;
}
