/*
ID: lbenc131
PROG: runround
LANG: C++
*/
#include <cstdio>
using namespace std;

#define ull unsigned long long

int num[10];
int len;

bool num2str(ull a)
{
    bool dig[10]={0};
    int i;
    for(i=0;a>0;i++)
    {
        if(a%10==0 || dig[a%10]) return false;
        num[i]=a%10;
        dig[a%10]=1;
        a/=10;
    }
    len=i;
    return true;
}

bool isRunaround(ull a)
{
    if(!num2str(a)) return false;

    bool pos[10]={0};
    int it=len-1;
    while(pos[it]==0)
    {
        pos[it]=1;
        it-=num[it]%len;
        if(it<0) it+=len;
    }
    if(it!=len-1) return false;
    for(int i=0;i<len;i++)
        if(pos[i]==0) return false;
    return true;
}

int main() {
    FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");

	ull m;
	fscanf(fin, "%llu", &m);

	do {
        m++;
    } while(!isRunaround(m));

    fprintf(fout, "%llu\n", m);
    return 0;
}
