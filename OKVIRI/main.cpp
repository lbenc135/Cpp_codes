#include <iostream>
#include <string>
using namespace std;

int main()
{
    string rijec;
    cin >> rijec;

    for(int i=0;i<5;i++)
    {
        if(i!=2) cout << ".";
        for(int j=0;j<rijec.length();j++)
        {
            if((j+1)%3==0 && i==0) cout << ".*..";
            else if(i==0) cout << ".#..";
            if((j+1)%3==0 && i==1) cout << "*.*.";
            else if(i==1) cout << "#.#.";

            if((j+1)%3==0 && i==2) cout << "*." << rijec[j] << ".*";
            else if(i==2 && (j+1)%4==0) cout << "." << rijec[j] << ".";
            else if(i==2) cout << "#." << rijec[j] << ".";


            if((j+1)%3==0 && i==3) cout << "*.*.";
            else if(i==3) cout << "#.#.";
            if((j+1)%3==0 && i==4) cout << ".*..";
            else if(i==4) cout << ".#..";

            if (i==2 && (j+1)%3!=0 && (j+1)==rijec.length()) cout << "#";
        }
        cout << endl;
    }
}
