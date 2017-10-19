#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int N, M, S[100][100];

    //ucitamo tablicu i inicijaliziramo tablicu S
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> S[i][j];

    //racunamo rjesenja svih potproblema
    // u celije iz prvog retka mozemo doci samo slijeva
    for(int i=1;i<M;i++)
        S[0][i] += S[0][i-1];

    // u celije iz prvog stupca mozemo doci samo odozgo
    for(int i=1;i<N;i++)
        S[i][0] += S[i-1][0];

    //u sve ostale celije mozemo doci slijeva ili odozgo
    for(int i=1;i<N;i++)
        for(int j=1;j<M;j++)
            S[i][j] += max(S[i][j-1],S[i-1][j]);

    cout << S[N-1][M-1] << endl;
}
