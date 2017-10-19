#include <iostream>

using namespace std;

int main()
{
    char rijec[15]={0};
    cin >> rijec;
    int duzina=0;
    for(int i=0;i<15;i++)
    {
        if(rijec[i]==0) break;
        duzina+=(rijec[i]-'A')/3 + 3;
    }
    cout << duzina;
}
