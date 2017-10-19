#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

#define MAXP 250000
#define pii pair<int,int>

pii ploce[MAXP];
int n, ploca, ppn, maxpd=-1, maxpdt;
bool visited[MAXP];
int put[MAXP];

struct stanje {
    int p, vrijeme;
    stanje(){}
    stanje(int p, int t)
    {
        this->p = p;
        vrijeme = t;
    }
};

stanje BFS()
{
    stanje start(0, 0), tr;
    queue<stanje> q;
    q.push(start);
    while(!q.empty())
    {
        tr=q.front();
        q.pop();
        visited[tr.p]=true;
        tr.vrijeme++;
        if(tr.p==ploca-1) return tr;

        if(tr.p>maxpd) {maxpd=tr.p; maxpdt=tr.vrijeme;}

        if(tr.p<ploca-1 && !visited[tr.p+1] && ploce[tr.p].second==ploce[tr.p+1].first)
            { q.push(stanje(tr.p+1, tr.vrijeme)); put[tr.p+1]=tr.p; }
        if(tr.p>0 && !visited[tr.p-1] && ploce[tr.p].first==ploce[tr.p-1].second)
            { q.push(stanje(tr.p-1, tr.vrijeme)); put[tr.p-1]=tr.p; }

        if(tr.p<ploca-n && (tr.p-n+1)%ppn && !visited[tr.p+n] && ploce[tr.p].second==ploce[tr.p+n].first)
            { q.push(stanje(tr.p+n, tr.vrijeme)); put[tr.p+n]=tr.p; }
        if(tr.p<ploca-n+1 && tr.p%ppn && !visited[tr.p+n-1] && ploce[tr.p].first==ploce[tr.p+n-1].second)
            { q.push(stanje(tr.p+n-1, tr.vrijeme)); put[tr.p+n-1]=tr.p; }

        if(tr.p>=n && tr.p%ppn && !visited[tr.p-n] && ploce[tr.p].first==ploce[tr.p-n].second)
            { q.push(stanje(tr.p-n, tr.vrijeme)); put[tr.p-n]=tr.p; }
        if(tr.p>=n-1 && (tr.p-n+1)%ppn && !visited[tr.p-n+1] && ploce[tr.p].second==ploce[tr.p-n+1].first)
            { q.push(stanje(tr.p-n+1, tr.vrijeme)); put[tr.p-n+1]=tr.p; }
    }
    return stanje(maxpd, maxpdt);
}

int main()
{
    scanf("%i", &n);
    ploca = n*n - n/2;
    ppn=n+n-1;
    for(int i=0;i<ploca;i++)
        scanf("%i %i", &ploce[i].first, &ploce[i].second);

    stanje r = BFS();
    printf("%i\n", r.vrijeme);
    int sl=r.p, pt[MAXP], it=0;
    do
    {
        pt[it]=sl+1;
        sl=put[sl];
        it++;
    } while(sl);
    printf("1 ");
    while(it--)
        printf("%i ", pt[it]);
}
