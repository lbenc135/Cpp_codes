#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, rijeci;
    cin >> n;
    string rijec[100], redak;
    for(int i=0;1;i++)
    {
        rijeci=i;
        cin >> rijec[i];
        if(cin.get()=='\n') break;
    }

    for(int i=0;i<=rijeci;i++)
    {
        redak=rijec[i];
        for(int j=i;redak.length()+1+rijec[j+1].length()<=n && i<rijeci;j++)
        {
            redak+='.'+rijec[j+1];
            i++;
        }
        if(redak.length()<n) redak.insert(0, n-redak.length(), '.');
        cout << redak << endl;
    }
}
