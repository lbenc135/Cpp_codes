#include <iostream>
#include <string>
using namespace std;

int main()
{
    string rijec;
    size_t pos;
    cin >> rijec;
    char cambridge[] = "CAMBRIDGE";
    for(int i=0;i<9;i++)
    {
        pos = rijec.find(cambridge[i]);
        if(pos != string::npos) rijec.erase(rijec.begin() + pos);
        if(rijec.find(cambridge[i]) != string::npos) i--;
    }

    cout << rijec;
}
