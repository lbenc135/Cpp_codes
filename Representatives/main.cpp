#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool pairCompare(pair<int, int> f, pair<int, int> s) {return f.first < s.first;}

int n, m;
pair<int, int> studenti[1000001];

int main()
{
   scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d", &studenti[i*m+j].first);
            studenti[i*m+j].second=i;
        }
    int nm=n*m;
    sort(studenti, studenti+nm, pairCompare);

    int mindif=1000000000;
    int difc=n, mini=1000000000, maxi;
    int a[n];
    memset(a, 0, sizeof(a));
    for(int i=0;i<nm;i++)
    {
        if(a[studenti[i].second]==0)
        {
            a[studenti[i].second]=studenti[i].first; difc--;
            maxi=studenti[i].first;
            if(studenti[i].first<mini) mini=studenti[i].first;
        }
        else
        {
            if(a[studenti[i].second]==mini)
            {
                a[studenti[i].second]=studenti[i].first;
                mini=1000000000;
                for(int i=0;i<n;i++)
                    if(a[i]<mini && a[i]!=0) mini=a[i];
                maxi=studenti[i].first;
            }
            else
            {
                a[studenti[i].second]=studenti[i].first;
                maxi=studenti[i].first;
            }
        }
        if(maxi-mini<mindif && difc==0) {mindif=maxi-mini;}
    }

    printf("%d", mindif);
}
