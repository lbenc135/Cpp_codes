#include <iostream>
using namespace std;

int main()
{
    int n, uk=0, dan=0, h1, m1;
    cin >> n;
    char com[n];
    int comsec[n], h, m, s, pt=0;
    int output[n][3];
    for(int i=0;i<n;i++)
    {
        cin >> com[i];
        if(com[i]=='P') uk++;
        cin >> h; cin.get();
        cin >> m; cin.get();
        cin >> s; cin.get();
        if(i>0 && (h*60*60 + m*60 + s + dan)<comsec[i-1]) dan+=86400;
        comsec[i]=h*60*60 + m*60 + s + dan;

        if(com[i]=='U')
        {
            output[pt][0] = uk;
            h1=0; m1=0;
            for(int j=i-1;j>=0;j--)
            {
                if(com[j]=='P' && comsec[i]-comsec[j]<=60) {m1++; h1++;}
                else if(com[j]=='P' && comsec[i]-comsec[j]<=3600) {h1++;}
            }
            output[pt][1] = h1;
            output[pt][2] = m1;
            pt++;
        }
    }
    for(int i=0;i<pt;i++)
        cout << output[i][0] << " " << output[i][1] << " " << output[i][2] << endl;
}
