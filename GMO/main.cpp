#include <iostream>
using namespace std;

int main()
{
    string n, m;
    cin >> n >> m;
    int cijena[4];
    for(int i=0;i<4;i++)
        cin >> cijena[i];

    int mini=100000000, temp, nlen=n.length(), mlen=m.length(), dalje=0;
    for(int i=0;i<nlen;i++)
    {
        temp=dalje=0;
        for(int j=0;j<mlen;j++)
        {
            if(n[i+dalje]!=m[j])
            {
                if(m[j]=='A')
                    temp+=cijena[0];
                else if(m[j]=='C')
                    temp+=cijena[1];
                else if(m[j]=='G')
                    temp+=cijena[2];
                else if(m[j]=='T')
                    temp+=cijena[3];
            }
            else dalje++;
        }
        if(temp<mini) mini=temp;
    }
    cout << mini;
}
