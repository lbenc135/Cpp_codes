#include <cstdio>
#include <algorithm>
using namespace std;

int polje[3][150001];
int n;
int state[3][150001];

void solve()
{
    state[0][0]=state[1][0]=polje[0][0];
    for(int i=1;i<n;i++)
        state[0][i]=state[0][i-1]+polje[0][i];
    for(int i=1;i<n;i++)
        state[1][i]=min(state[1][i-1], state[0][i-1])+polje[1][i];
    state[2][1]=state[1][1];
    for(int i=2;i<n;i++)
        state[2][i]=min(state[2][i-1], state[1][i-1])+polje[2][i];
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
            scanf("%i", &polje[i][j]);
    solve();
    printf("%i\n", state[2][n-1]);
}
