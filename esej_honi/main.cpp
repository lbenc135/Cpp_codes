#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

map<string, bool> m;

string rand_word()
{
    string a;
    a.push_back(rand()%26+'a');
    a.push_back(rand()%26+'a');
    a.push_back(rand()%26+'a');
    a.push_back(rand()%26+'a');
    a.push_back(rand()%26+'a');
    return a;
}

int main()
{
    srand(time(0));

    int a, b;
    cin >> a >> b;

    string s;
    for(int i=0;i<a;i++)
    {
        s=rand_word();
        if(!m[s])
        {
            m[s]=1;
            cout << s << ' ';
        }
        else i--;
    }
}
