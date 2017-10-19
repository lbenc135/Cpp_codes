/*
ID: lbenc131
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

string nk;
string neck;
bool used[351];

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

	int n;
	fin >> n >> nk;
    neck=nk+nk+nk;
	int cnt=0;
	for(int i=0;i<n;i++)
    {
        memset(used, 0, sizeof(used));
        int templ=0, tempr=0;
        char l, r;
        r=neck[(i+1)%n];
        l=neck[(i+n-1)%n];

        for(int j=i;j>=0;j--)
        {
            if(l=='w' && neck[j]!='w') l=neck[j];
            if((neck[j]==l || neck[j]=='w') && !used[j%n]) {templ++; used[j%n]=true;}
            else break;
        }
        for(int j=i+1;j<3*n;j++)
        {
            if(r=='w' && neck[j]!='w') r=neck[j];
            if((neck[j]==r || neck[j]=='w') && !used[j%n]) {tempr++; used[j%n]=true;}
            else break;
        }
        if(templ+tempr>cnt) cnt=templ+tempr;
    }
    fout << cnt << endl;

    return 0;
}
