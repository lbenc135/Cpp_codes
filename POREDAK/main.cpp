#include <iostream>
#include <string>
using namespace std;

int findstr(string a);

string tpojam[2500];
string pojam[2500];
int n;

int main()
{
    int bodova=0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> tpojam[i];
    for(int i=0;i<n;i++)
        cin >> pojam[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(findstr(pojam[i])>findstr(pojam[j]) && i>j) bodova++;
            if(findstr(pojam[i])<findstr(pojam[j]) && i<j) bodova++;
        }
    cout << bodova/2 << '/' << n*(n-1)/2;
}

int findstr(string a)
{
    for(int i=0;i<n;i++)
        if(tpojam[i]==a) return i;
    return -1;
}
