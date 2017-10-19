/*
ID: lbenc131
PROG: hamming
LANG: C++
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

int hamDist(int a, int b)
{
    int r=0;
    int c=a^b;
    while(c)
    {
        c-=c&-c;
        r++;
    }
    return r;
}

int main()
{
    FILE *fin  = fopen ("hamming.in", "r");
    FILE *fout = fopen ("hamming.out", "w");

    int n, b, d;
    fscanf(fin, "%i %i %i", &n, &b, &d);
    for(int i=0;i<(1<<b) && v.size()<n;i++)
    {
        bool can=1;
        for(int j=0;j<v.size();j++)
            if(hamDist(i, v[j])<d) can=0;
        if(can) v.push_back(i);
    }
    for(int i=0;i<v.size();i++)
    {
        fprintf(fout, "%i", v[i]);
        if((i+1)%10==0 && i) fprintf(fout, "\n");
        else if(i==v.size()-1) fprintf(fout, "\n");
        else fprintf(fout, " ");
    }
    return 0;
}
