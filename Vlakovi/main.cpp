#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int l, s, v;
    cin >> l >> s >> v;
    int postaja[s];
    for(int i=0;i<s;i++)
        cin >> postaja[i];
    int vlak[v];
    for(int i=0;i<v;i++)
        cin >> vlak[i];

    int vrijeme[v];
    memset(vrijeme, 0, sizeof(vrijeme));
    vrijeme[v-1]=postaja[s-1]-vlak[v-1];
    int pt;
    int stajao[v][s];
    memset(stajao, 0, sizeof(stajao));
    int pozv;
    for(int i=v-2;i>=0;i--)
    {
        pt=i+1;
        while(postaja[pt]<vlak[i]) pt++;
        vrijeme[i]+=postaja[pt]-vlak[i];
        while(pt<s-1)
        {
            pt++;
            pozv=vlak[i+1]+vrijeme[i];
            for(int j=pt-1;j>=0;j--)
                pozv-=stajao[i+1][j];
            if(pozv<postaja[pt]) {vrijeme[i]+=(stajao[i][pt-1]=postaja[pt]-pozv);}
            vrijeme[i]+=postaja[pt]-postaja[pt-1];
        }
    }

    for(int i=0;i<v;i++)
        cout << vrijeme[i] << endl;
}

