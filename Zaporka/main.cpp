#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    bool del=false;
    cin >> n;
    string uzorci[n];
    for(int i=0;i<n;i++)
        cin >> uzorci[i];

    string arr[n][100];
    int pon[100]={0};
    int pt=0;

    for(int i=0;i<n;i++)
    {
       for(int j=0;1;j++)
        {
            if(j==uzorci[i].length()) {j=0; pt++;}
            char ch=uzorci[i][j];
            if(ch=='(') del=true;
            else if(ch==')') {del=false; arr[i][pt].append(uzorci[i], uzorci[i].find(')')+1, string::npos); break;}
            else if(ch=='|') {del=false; uzorci[i].erase(uzorci[i].begin()+j); j=uzorci[i].find(')');}
            else
            {
                arr[i][pt].append(1, ch);
                if(del==true) {uzorci[i].erase(uzorci[i].begin()+j); j--;}
            }
        }
        pt=0;
    }

    int pona=1;
    for(int i=0;i<100;i++)
    {
        for(int j=1;j<n;j++)
            for(int k=0;k<100;k++)
                if(!arr[0][i].compare(arr[j][k])) pona++;
        if(pona==n) {cout << arr[0][i]; break;}
        pona=1;
    }
}
