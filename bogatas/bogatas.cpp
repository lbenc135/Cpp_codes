#include <iostream>
using namespace std;

int main()
{
    int x,y;
    int p;
    int n;
    cin >> n >> p;
    int map1[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            map1[i][j]=0;
    }
    for (int i=0;i<p;i++)
    {
        cin >> x >> y;
        map1[x-1][y-1]=1;
    }

    int nv=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int dim=1, dimt=1;
            if(map1[i][j]!=1)
            {
                int tx=i+1,ty=j+1;
                while(tx<n)
                {
                    if(map1[tx][j]==0)
                        dim++;
                    else break;
                    tx++;
                }
                tx=i+1; ty=j+1;
                while(ty<n)
                {
                    if(map1[i][ty]==0)
                        dimt++;
                    else break;
                    ty++;
                }
                if (dimt<dim) dim=dimt;
                for(int k=i;k<i+dim;k++)
                {
                    for(int l=j;l<j+dim;l++)
                    {
                        if(map1[k][l]==1)
                        {
                            if((k-i)<(l-j))
                                dim=l-j;
                            else
                                dim=k-i;
                        }
                    }
                }
            }
            if(dim>nv)
                nv=dim;
        }
    }
    cout << nv << endl;
}
