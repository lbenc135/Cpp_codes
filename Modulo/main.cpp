#include <iostream>
using namespace std;

int main()
{
    int mods[42];
    for(int i=0;i<42;i++) mods[i]=-1;
    int a, it=0, result=0;
    bool in;
    for(int i=0;i<10;i++)
    {
        in=false;
        cin >> a;
        a%=42;
        for(int j=0;j<10;j++)
        {
            if(a==mods[j]) in = true;
        }
        if(in==false) {mods[it] = a; it++; result++;}
    }
    if(result==0) cout << 1 << endl;
    else cout << result << endl;
}
