#include <cstdio>
#include <iostream>
using namespace std;

int f, m;
int tr[3];

int main()
{
    scanf("%i", &f);
    int o[11], v[11], n[11];
    for(int i=0;i<f;i++)
        scanf("%i-%i-%i", &o[i], &v[i], &n[i]);
    scanf("%i", &m);
    string s[23];
    for(int i=0;i<m;i++)
        cin >> s[i];

    for(int j=0;j<m;j++)
    {
        for(int k=0;k<s[j].length();k++)
        {
            if(s[j][k]=='O')
                tr[0]++;
            else if(s[j][k]=='V')
                tr[1]++;
            else if(s[j][k]=='N')
                tr[2]++;
        }
    }

    for(int i=0;i<f;i++)
    {
        if(tr[0]>=o[i] && tr[1]>=v[i] && tr[2]>=n[i])
            printf("DA\n");
        else
            printf("NE\n");
    }

    return 0;
}
