#include <iostream>
#include <cstdio>
using namespace std;

string whichLang(string a);
string convert2C(string a);
string convert2J(string a);

int main()
{
    char w[101];
    while(scanf("%s", w)>0)
    {
        string word(w);
        cout << whichLang(word) << endl;
    }
}

string whichLang(string a)
{
    if(!(a[0]<='z' && a[0]>='a') || a[0]=='_' || a[a.length()-1]=='_')
        return "Error!";

    bool is = true;
    int len = a.length();
    for(int i=0;i<len-1;i++)
        if(a[i]=='_' && a[i+1]=='_')
            return "Error!";

    for(int i=0;i<len;i++)
        if(!(a[i]<='z' && a[i]>='a' || a[i]=='_')) is = false;
    if(is)
        return convert2J(a);

    is = true;
    for(int i=0;i<len;i++)
        if(!(a[i]<='z' && a[i]>='a' || a[i]<='Z' && a[i]>='A')) is = false;
    if(is)
        return convert2C(a);

    return "Error!";
}

string convert2C(string x)
{
    string a = x;
    for(int i=0;i<a.length();i++)
        if(a[i]<='Z' && a[i]>='A') {
            a[i]+=32;
            a.insert(i, 1, '_');
        }
    return a;
}

string convert2J(string x)
{
    string a = x;
    for(int i=0;i<a.length();i++)
        if(a[i]=='_') {
            a.erase(i, 1);
            if(a[i]<='z' && a[i]>='a')
                a[i]-=32;
            i--;
        }
    if(a[0]<='Z' && a[0]>='A')
        a[0]+=32;
    return a;
}
