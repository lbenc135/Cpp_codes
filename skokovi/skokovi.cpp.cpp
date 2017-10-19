#include <iostream>
using namespace std;

int main()
{
    int k, d, mino=20, maxo=0;
    int ocjene[5];
    cin >> k >> d;
    for(int i=0;i<5;i++)
    {
        cin >> ocjene[i];
        if(ocjene[i]<mino) mino=ocjene[i];
        if(ocjene[i]>maxo) maxo=ocjene[i];
    }


    int bodova=60+(d-k)*2-mino-maxo;
    for(int i=0;i<5;i++)
    {
        bodova+=ocjene[i];
    }

    cout << bodova;
}
