#include <iostream>
using namespace std;

int main()
{
    int g;
    int ns=0, ps=0, rm=0, im=0, is=0;
    for(int i=0;i<5;i++)
    {
        cin >> g;
        if(g<200) ns++;
        else if(g<370) ps++;
        else if(g<470) rm++;
        else if(g<570) im++;
        else if(g>=570) is++;
    }
    cout << ns << ' ' << ps << ' ' << rm << ' ' << im << ' ' << is;
}
