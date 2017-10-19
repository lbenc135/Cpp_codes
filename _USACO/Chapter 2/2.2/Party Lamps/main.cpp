/*
ID: lbenc131
PROG: lamps
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

FILE *fin, *fout;
int n, c;
int zadano[101];
bool trenutno[101];
vector<string> sol;

bool isMaskOK(int m)
{
    int s=0;
    while(m>0)
    {
        m-=m&-m;
        s++;
    }
    switch(c)
    {
    case 0:
        if(s==0) return true;
        return false;
    case 1:
        if(s==1) return true;
        return false;
    case 2:
        if(s==0 || s==2) return true;
        return false;
    case 3:
        if(s==1 || s==3) return true;
        return false;
    case 4:
        if(s==0 || s==2 || s==4) return true;
        return false;
    }
    return false;
}

void btn(int b)
{
    switch(b)
    {
    case 0:
        for(int i=0;i<n;i++)
            trenutno[i]=!trenutno[i];
        break;
    case 1:
        for(int i=0;i<n;i+=2)
            trenutno[i]=!trenutno[i];
        break;
    case 2:
        for(int i=1;i<n;i+=2)
            trenutno[i]=!trenutno[i];
        break;
    case 3:
        for(int i=0;3*i<n;i++)
            trenutno[3*i]=!trenutno[3*i];
        break;
    }
}

void store()
{
    string s;
    for(int i=0;i<n;i++)
        s.push_back(trenutno[i]+'0');
    sol.push_back(s);
}

void print()
{
    sort(sol.begin(), sol.end());
    for(int i=0;i<sol.size();i++)
        fprintf(fout, "%s\n", sol[i].c_str());
}

void init()
{
    memset(zadano, -1, sizeof(zadano));
    /* C=1 - 1 korak
    C=2 - 0 ili 2 koraka
    C=3 - 1 ili 3 koraka
    C=4 - 0, 2 ili 4 koraka
    */
    if(c>4)
    {
        switch(c%4)
        {
        case 0:
        case 2:
            c=4;
            break;
        case 1:
        case 3:
            c=3;
            break;
        }
    }
}

int main() {
    fin  = fopen ("lamps.in", "r");
    fout = fopen ("lamps.out", "w");

	int temp;
	fscanf(fin, "%i %i", &n, &c);
	init();

	while(1)
	{
	    fscanf(fin, "%i", &temp);
	    if(temp==-1) break;
	    zadano[temp-1]=1;
	}
	while(1)
	{
	    fscanf(fin, "%i", &temp);
	    if(temp==-1) break;
	    zadano[temp-1]=0;
	}

    bool impossible=true;
	for(int i=0;i<(1<<4);i++)
    {
        if(!isMaskOK(i)) continue;
        memset(trenutno, 1, sizeof(trenutno));

        for(int j=0;j<4;j++)
        {
            int bm=(1<<j);
            if(i&bm) btn(j);
        }

        bool can=1;
        for(int i=0;i<n;i++)
            if(zadano[i]!=-1 && zadano[i]!=trenutno[i])
            {
                can=0;
                break;
            }
        if(can) store();
    }

    if(sol.size()==0)
        fprintf(fout, "IMPOSSIBLE\n");
    else
        print();

    return 0;
}
