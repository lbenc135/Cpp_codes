#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

string calczn(char a, int p);
string strmnozi(string a, char b);
string zbrstr(string n, string z);
string num[10];

int main()
{
    num[0]="0";
    for(int i=1;i<10;i++)
        num[i]="-1";
    string n;
    cin >> n;
    int start_s=clock();
    string zbroj="0";
    int znamenki=n.length();
    for(int i=0;i<znamenki;i++)
    {
        zbroj = zbrstr(zbroj, calczn(n[i], znamenki));
    }
    int stop_s=clock();
    if(zbroj==n) cout << "narcisoidan";
    else cout << "nije narcisoidan";

    cout << endl << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
}

string calczn(char a, int p)
{
    if(num[a-'0']!="-1") return num[a-'0'];
    string rez="1";
    for(int i=0;i<p;i++)
    {
        rez = strmnozi(rez, a);
    }
    num[a-'0'] = rez;
    return rez;
}

string strmnozi(string a, char b)
{
    string mn;
    int dalje=0, zn;
    for(int j=a.length()-1;j+(dalje>0?1:0)>=0;j--)
    {
        if(j>=0) zn=(a[j]-'0')*(b-'0') + dalje;
        else zn=dalje;
        if(zn>9)
        {
            dalje=zn/10;
            zn%=10;
        }
        else dalje=0;
        mn.insert(0, 1, (zn+'0'));
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
