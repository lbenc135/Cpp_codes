#include <iostream>
using namespace std;

int main()
{
    string a, b;
    while(cin >> a >> b) {
        int let[26] = {0}, let2[26]={0};
        int len = a.length();
        for(int i=0;i<len;i++)
            let[a[i]-'a']++;
        len = b.length();
        for(int i=0;i<len;i++)
            let2[b[i]-'a']++;

        for(int i=0;i<26;i++)
            if(let[i]>0 && let2[i]>0)
                for(int j=0;j<min(let[i], let2[i]);j++)
                    cout << (char)(i+'a');
        cout << endl;
    }
}
