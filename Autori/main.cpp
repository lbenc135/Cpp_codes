#include <iostream>
using namespace std;

char ime[100];

int main()
{
    cin >> ime;
    for(int i=0;i<100;i++)
        if(ime[i]>=65 && ime[i]<=90) cout << ime[i];
}
