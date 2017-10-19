#include <iostream>
using namespace std;

string m="22233344455566677778889999";

int n;
string r[1001];
string s;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
      cin >> r[i];
    cin >> s;

    int len=s.length();
    int zbr=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<len;j++)
            if(m[r[i][j]-'a'] != s[j])
            {
                zbr--;
                break;
            }

        zbr++;
    }

    cout << zbr;
}
