#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int n, max=0, temp, it, po;
    cin >> a >> n;
    string  p[n];
    int f[n], s[n];
    for(int i=0;i<n;i++)
        cin >> p[i] >> f[i] >> s[i];


    for(int i=0;i<a.length();i++)
        for(int j=1;j<=a.length()-i;j++)
        {
            po=0;
            for(int k=0;k<n;k++)
            {
                temp=0;
                it = p[k].find(a.substr(i, j));
                while(it!=string::npos)
                {
                    temp++;
                    it = p[k].find(a.substr(i, j), it+1);
                }
                if(temp<=s[k] && temp>=f[k]) po++;
            }
            if(po==n) max++;
        }
    cout << max;
}
