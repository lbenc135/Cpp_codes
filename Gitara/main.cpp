#include <iostream>
using namespace std;

int main()
{
    int n, p, pokreta=0, pt[6]={0};
    cin >> n >> p;
    int zica[n], prag[n];
    for(int i=0;i<n;i++)
        cin >> zica[i] >> prag[i];

    int gitara[6][n];
    for(int i=0;i<6;i++)
        for(int j=0;j<n;j++)
            gitara[i][j]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;gitara[zica[i]][j]!=0;j++)
        {
            if(gitara[zica[i]][j]>prag[i]) {pokreta++; gitara[zica[i]][j]=-1;}
            if(gitara[zica[i]][j]==prag[i]) {pokreta--; gitara[zica[i]][j]=-1;}
        }

        pokreta++;
        gitara[zica[i]][pt[zica[i]]]=prag[i];
        pt[zica[i]]++;
    }

    cout << pokreta;
}
