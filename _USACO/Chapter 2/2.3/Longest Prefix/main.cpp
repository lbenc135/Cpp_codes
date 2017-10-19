/*
ID: lbenc131
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define BASE 1337
#define ull unsigned long long

string s, temp;
vector<string> pref;
bool available[200001]={1};

ull hashS[200001];
ull hashPref[201];
ull b[200001]={1};

bool pase(int p, int i)
{
    if(p==0)
    {
        if(hashPref[i]==hashS[p+pref[i].length()-1])
            return true;
    }
    else if(p!=0)
    {
        if(hashPref[i]*b[p]==hashS[p+pref[i].length()-1]-hashS[p-1])
            return true;
    }

    return false;
}
/*
bool pase(int p, int i)
{
    for(int j=0;j<pref[i].length();j++)
    {
        if(s[p+j]!=pref[i][j]) return false;
    }
    return true;
}
*/
int maxpref()
{
    int maks=0;
    for(int p=0;p<s.length();p++)
    {
        if(available[p])
            for(int i=0;i<pref.size();i++)
            {
                if(pase(p, i))
                {
                    available[p+pref[i].length()]=1;
                    if(p+pref[i].length()>maks)
                        maks=p+pref[i].length();
                }
            }
    }
    return maks;
}

void initHashes()
{
    for(int i=0;i<s.length();i++)
    {
        if(i!=0)
        {
            b[i]=b[i-1]*BASE;
            hashS[i]=s[i]*b[i]+hashS[i-1];
        }
        else
            hashS[i]=s[i]*b[i];
    }

    for(int i=0;i<pref.size();i++)
        for(int j=0;j<pref[i].length();j++)
            hashPref[i]+=pref[i][j]*b[j];
}

int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    while(true)
    {
        fin >> temp;
        if(temp==".") break;
        pref.push_back(temp);
    }
    while(fin >> temp)
        s.append(temp);

    initHashes();

    fout << maxpref() << endl;
    return 0;
}
