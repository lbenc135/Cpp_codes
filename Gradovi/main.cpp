#include <iostream>
using namespace std;

void visit(int grad);

bool ceste[1000][1000] = {false};
bool visited[1000] = {false};
int n;

int main()
{
    int k,a,b;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> a >> b;
        ceste[a-1][b-1] = ceste[b-1][a-1] = true;
    }

    int grupa=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            grupa++;
            visit(i);
        }
    }
    cout << grupa-1;
}


void visit(int grad)
{
    visited[grad]=true;
    for(int i=0;i<n;i++)
    {
        if(ceste[i][grad]==true && i!=grad && visited[i]==false)
            visit(i);
    }
}
