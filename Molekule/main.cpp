#include <iostream>
#include <vector>
using namespace std;

int n, a[100001], b[100001];
vector<int> v[100001];
bool visited[100001];
bool m[100001];  // m[i]==0 -> veza ide iz nj; m[i]==1 -> veza ide u nj

void blackNwhite(int it)
{
    visited[it]=1;
    for(int i=0;i<v[it].size();i++)
    {
        m[v[it][i]]=!m[it];
        if(!visited[v[it][i]]) blackNwhite(v[it][i]);
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }


    blackNwhite(1);

    for(int i=0;i<n-1;i++)
    {
        if(m[a[i]]==0) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
