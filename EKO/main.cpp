#include <cstdio>
using namespace std;

int drva[1000001];

int main()
{
    unsigned int n, m;
    int l=0, h=0;
    scanf("%i %i", &n, &m);
    for(int i=0;i<n;i++)
    {
        scanf("%i", &drva[i]);
        if(drva[i]>h) h=drva[i];
    }

    int mid;
    long long sum;
    while(l<h)
    {
        sum=0;
        mid=(l+h+1)/2;
        for(int i=0;i<n;i++)
            if(drva[i]>mid) sum+=drva[i]-mid;
        if(sum<m)
            h=mid-1;
        else if(sum>m)
            l=mid;
        else
        {
            l=mid;
            break;
        }
    }
    printf("%i\n", l);
}
