#include <iostream>
using namespace std;

int mat[27][14];
char sl[]={'p'-'a', 'k'-'a', 'h'-'a', 't'-'a'};

int main()
{
    string s;
    cin >> s;
    int br=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        switch(i%3)
        {
        case 0:
            mat[s[i]-'A'][br]++;
            if(mat[s[i]-'A'][br]>1)
            {
                cout << "GRESKA";
                return 0;
            }
            br=0;
            break;
        case 1:
            br+=(s[i]-'0')*10;
            break;
        case 2:
            br+=s[i]-'0';
            break;
        }
    }

    for(int i=0;i<4;i++)
    {
        br=0;
        for(int j=1;j<=13;j++)
        {
            if(mat[sl[i]][j]==0) br++;
        }
        cout << br << ' ';
    }

}
