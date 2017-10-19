#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        bool mag=true;
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++)
        {
            for(int k=1;k<=s.length();k++)
            {
                string str=s.substr(j,k);
                if(s.find(string(str.rbegin(),str.rend()))==string::npos) mag=false;
            }
        }
        if(mag==true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
