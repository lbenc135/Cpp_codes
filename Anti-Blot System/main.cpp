#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        string s;
    int a,b,c;
    cin >> s;
    if(s.find("machula")!=string::npos) s = "-1";
    istringstream buffer(s);
    buffer >> a;

    cin.get();
    cin.get();

    cin >> s;
    if(s.find("machula")!=string::npos) s = "-1";
    istringstream buf(s);
    buf >> b;

    cin.get();
    cin.get();

    cin >> s;
    if(s.find("machula")!=string::npos) s = "-1";
    istringstream buff(s);
    buff >> c;


    if(a==-1) cout << c-b << " + " << b << " = " << c << endl;
    if(b==-1) cout << a << " + " << c-a << " = " << c << endl;
    if(c==-1) cout << a << " + " << b << " = " << a+b << endl;
    }
}
