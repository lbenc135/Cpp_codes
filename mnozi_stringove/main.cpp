#include <iostream>
#include <string>
using namespace std;

string strmnozi(string a, string b);
string zbrstr(string n, string z);

int main()
{
    string a="23", b="92";
    cout << strmnozi(a, b);
}

string strmnozi(string a, string b)
{
    string temp, mn="0";
    int dalje=0, zn;
    for(int i=0;i<b.length();i++)
    {
        temp="";
        for(int j=a.length()-1;j+(dalje>0?1:0)>=0;j--)
        {
            if(j<0) zn=dalje;
            else zn=(a[j]-'0')*(b[i]-'0') + dalje;
            if(zn>9)
            {
                dalje=zn/10;
                zn%=10;
            }
            else dalje=0;
            temp.insert(0, 1, (zn+'0'));
        }
        temp.insert(temp.end(), b.length()-i-1, '0');
        mn = zbrstr(mn, temp);
    }
    return mn;
}

string zbrstr(string n, string z)
{
    string rez, temp;
    if(n.length()<z.length())
    {
        temp=n;
        n=z;
        z=temp;
    }
    int pt1, pt2, zn, dalje=0;
    for(int i=1;pt2>0;i++)
    {
        pt1=n.length()-i;
        pt2=z.length()-i;
        zn=n[pt1]-'0' + z[pt2]-'0' + dalje;
        if(zn>9)
        {
            zn-=10;
            dalje=1;
        }
        else dalje=0;
        rez.insert(0, 1, (zn+'0'));
    }
    pt1--;
    if(dalje>0)
    {
        if(pt1<0) rez.insert(0, 1, '1');
        else n[pt1]+=dalje;
    }
    while(pt1>=0)
    {
        rez.insert(0, 1, n[pt1]);
        pt1--;
    }
    return rez;
}
