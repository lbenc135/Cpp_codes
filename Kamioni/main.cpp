// PRESPORO! potrebna dinamika
#include <cstdio>
#include <cstring>
using namespace std;

int p, k, l;
char park[1002];
int car[1001], cars=0;
bool visited[1001];

int hasPlace(int it)
{
    int pl=0;
    for(int i=it;i<p;i++)
    {
        if(park[i]=='.') pl++;
        else if(pl<l) return false;

        if(pl>=l) return true;
    }
    return false;
}

bool isSolved()
{
    int tk=k;
    for(int i=0;i<p;i++)
    {
        if(hasPlace(i))
        {
            tk--;
            i+=l-1;
        }
        if(tk<=0) return true;
    }
    return false;
}

bool rek(int s)
{
    if(s==0)
    {
        if(isSolved()) return true;
        else return false;
    }
    for(int i=0;i<cars;i++)
    {
        if(!visited[i])
        {
            bool can=false;
            park[car[i]]='.';
            visited[i]=true;
            if(rek(s-1)) can=true;
            park[car[i]]='#';
            visited[i]=false;
            if(can) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%i %i %i", &p, &k, &l);
    for(int i=0;i<p;i++)
    {
        scanf(" %c", &park[i]);
        if(park[i]=='#') car[cars++]=i;
    }

    int lo=0, hi=cars+1, mid;
    while(lo<hi)
    {
        mid=(lo+hi)/2;

        if(rek(mid)) hi=mid;
        else lo=mid+1;
    }
    printf("%i\n", lo);
}
