#include <cstdio>
#include <algorithm>
using namespace std;

struct item {
    int w, v;

    bool operator<(const item &a) const {
        return v>a.v;
    }
};

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    int w, v;
    int m[k];
    item items[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i %i", &w, &v);
        items[i].v=v;
        items[i].w=w;
    }
    for(int i=0;i<k;i++)
        scanf("%i", &m[i]);

    sort(m, m+k);
    sort(items, items+n);
    long long rez=0;

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<k;i++)
            if(items[j].w<=m[i])
            {
                rez+=items[j].v;
                m[i]=-1;
                break;
            }
    }
    printf("%i", rez);
}
