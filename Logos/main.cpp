#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

char l[1001];
int c[1001];
int stanje[1001][1001][2];

int rek(int a, int b, int t1)
{
    if(b-a==1)
    {
        if(l[a]==t1+'0') return 0;
        else return c[a];
    }
    a++; b--;
    if(stanje[a][b][t1]!=-1) return stanje[a][b][t1];

    int zagrada=0;
    char veznik;
    vector<pair<int,int> > v;
    int poc=a;
    for(int i=a;i<b;i++)
    {
        if(l[i]=='(') zagrada++;
        else if(l[i]==')') zagrada--;
        if(zagrada==0 && l[i]!='0' && l[i]!='1' && l[i]!=')')
        {
            if(l[i]=='|')
                veznik='|';
            else if(l[i]=='&')
                veznik='&';
            else if(l[i]=='^')
                veznik='^';
            v.push_back(pair<int,int>(poc, i));
            poc=i+1;
        }
    }
    v.push_back(pair<int,int>(poc, b));

    if(t1==0)
    {
        if(veznik=='|') veznik='&';
        else if(veznik=='&') veznik='|';
    }

    if(veznik=='|')
    {
        int mini=10000000000;
        for(int i=0;i<v.size();i++)
        {
            int cost=rek(v[i].first, v[i].second, t1);
            if(cost<mini) mini=cost;
        }
        return stanje[a][b][t1]=mini;
    }
    else if(veznik=='&')
    {
        int zbr=0;
        for(int i=0;i<v.size();i++)
        {
            int cost=rek(v[i].first, v[i].second, t1);
            zbr+=cost;
        }
        return stanje[a][b][t1]=zbr;
    }
    else if(veznik=='^')
    {
        int mini=10000000000;
        int c1=0, c2=0;
        for(int i=0;i<v.size();i++)
        {
            int cost1=rek(v[i].first, v[i].second, 1);
            int cost2=rek(v[i].first, v[i].second, 0);
            if(cost1!=0) c1++;
            else c2++;

            if(cost1<mini && cost1!=0) mini=cost1;
            if(cost2<mini && cost2!=0) mini=cost2;
        }
        if(c2%2) mini=0;
        return stanje[a][b][t1]=mini;
    }
    return 0;
}

int main()
{
    scanf("%s", &l);
    int len=strlen(l);
    for(int i=0;i<len;i++)
        if(l[i]=='0' || l[i]=='1')
            scanf("%i", &c[i]);

    memset(stanje, -1, sizeof(stanje));
    printf("%i", rek(0, len, 1));
}
