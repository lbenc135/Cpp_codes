#include <iostream>
using namespace std;

int main()
{
    int n, v, k, songs=0;
    bool nova;
    cin >> n >> v;
    int man[100]={0};
    for(int i=0;i<v;i++)
    {
        cin >> k;
        int vecer[k];
        nova=false;
        for(int j=0;j<k;j++)
        {
            cin >> vecer[j];
            if(vecer[j]==1) {nova=true; songs++;}
        }
        for(int j=0;j<k;j++)
        {
            if(nova)
                man[vecer[j]]++;
            else
                man[vecer[j]]=songs;
        }
    }

    for(int i=1;i<=n;i++)
        if(man[i]==songs) cout << i << endl;
}
