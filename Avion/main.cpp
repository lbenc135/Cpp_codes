#include <iostream>
#include <string>
using namespace std;

int main()
{
    int st[5]={0};
    bool away=true;
    for(int i=0;i<5;i++)
    {
        string s;
        cin >> s;
        if(s.find("FBI")!=string::npos) st[i]++;
    }
    for(int i=0;i<5;i++)
    {
        if(st[i]==1) {cout << i+1 << " ";away=false;}
    }
    if(away==true) cout << "HE GOT AWAY!";
}
