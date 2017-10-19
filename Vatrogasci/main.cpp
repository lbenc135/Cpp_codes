#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long zbrojid(int dx, int dy, int k);

vector<vector<int > > domovi;
int x[100], y[100];
int dx[100], dy[100];
int n, k;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];

    for(int i=0;i<k;i++)
        {dx[i]=x[i]; dy[i]=y[i];}

    bool izmjena=true;
    int temp, mind;
    long zbroj, tzbroj;
    while(izmjena)
    {
        domovi.clear();
        domovi.resize(k);
        izmjena=false;
        for(int i=0;i<n;i++)
        {
            mind = 10000000;
            for(int j=0;j<k;j++)
                if(abs(x[i]-dx[j]) + abs(y[i]-dy[j]) < mind)
                    {mind=abs(x[i]-dx[j]) + abs(y[i]-dy[j]); temp=j;}
            domovi[temp].push_back(i);
        }

        for(int i=0;i<k;i++)
        {
            zbroj=zbrojid(dx[i], dy[i], i);
            for(int j=0;j<domovi[i].size();j++)
            {
                tzbroj=zbrojid(x[domovi[i][j]], y[domovi[i][j]], i);
                if(tzbroj<zbroj) {dx[i]=x[domovi[i][j]]; dy[i]=y[domovi[i][j]]; izmjena=true;}
            }
        }
    }

    for(int i=0;i<k;i++)
        cout << dx[i] << " " << dy[i] << endl;
    return 0;
}

long zbrojid(int dx, int dy, int k)
{
    long zbroj=0;
    for(int j=0;j<domovi[k].size();j++)
    {
        zbroj+=pow(abs(dx-x[domovi[k][j]]), 2) + pow(abs(dy-y[domovi[k][j]]), 2);
    }
    return zbroj;
}
