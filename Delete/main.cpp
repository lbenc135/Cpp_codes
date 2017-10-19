#include <iostream>
#include <vector>
using namespace std;

int n;
string word, dict[51], cur="*";
vector<string> parts;

void getParts()
{
    string temp;
    for(int i=0;i<cur.length();i++)
    {
        if(cur[i]=='*')
        {
            if(temp.length()>0)
                parts.push_back(temp);
            temp="";
        }
        else temp+=cur[i];
    }
    if(temp.length()>0)
        parts.push_back(temp);
}

bool isGood(int pos, int it)
{
    int len=parts[it].length();
    for(int i=pos;i<pos+len;i++)
        if(parts[it][i-pos]!=word[i]) return false;
    return true;
}

bool check()
{
    getParts();

    // provjeri dali zadovoljava koja rijec uzorak, ako da -> return false
}

void makeWord()
{
    // gradi rijec

    if(check()) return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> word >> n;
        for(int i=0;i<n;i++)
            cin >> dict[i];

        makeWord();
        cout << cur << endl;
    }
    return 0;
}
