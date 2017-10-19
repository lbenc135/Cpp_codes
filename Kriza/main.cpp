#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int s, t;
    cin >> s;
    string a[s], c[s];
    for(int i=0;i<s;i++)
        cin >> a[i] >> c[i];
    cin >> t;
    pair<string, int> art;
    vector<pair<string, int> > paket[t];
    int k, cijena[t];
    for(int i=0;i<t;i++)
    {
        cin >> k;
        cin >> art.first >> art.second;
        paket[i].push_back(art);
        cin >> cijena[i];
    }


}
