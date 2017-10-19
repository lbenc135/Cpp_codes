//KRIVO!!
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int pages[501];
vector<int> sc[501];
int sum=0, t, m, k, maksl;

int binary(int b, int k, int maxi)
{
    if(k==1) return sum;
    if(b==k) return pages[k-1];
    int l=maxi, h=min(sum-1, maksl), mid;
    while(l<h)
    {
        mid=(l+h)/2;
        int s=1, u=0;
        for(int i=0;i<b;i++)
            if(u+pages[i]<=mid) u+=pages[i];
            else {s++; u=pages[i];}
        if(s>=k)
            l=mid+1;
        else
            h=mid;
    }
    return l;
}

void binary1(int maxi)
{
    int l=maxi, h=sum, mid;
    while(l<h)
    {
        mid=(l+h)/2;
        int s=1, u=0;
        for(int i=0;i<m;i++)
            if(u+pages[i]<=mid) u+=pages[i];
            else {s++; u=pages[i];}
        if(s>k)
            l=mid+1;
        else
            h=mid;
    }
    maksl = l;
}

int main()
{
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i %i", &m, &k);
        for(int i=0;i<m;i++)
        {
            scanf("%i", &pages[i]);
            sum+=pages[i];
        }
        int u=0, b=m;
        maksl=0;
        for(int j=k;j>0;j--)
        {
            int maxi=0;
            for(int c=0;c<b;c++)
                if(pages[c]>maxi) maxi=pages[c];
            if(maksl==0) binary1(maxi);
            int l = binary(b, j, maxi);
            for(int i=b-1;i>=0;i--)
            {
                if(u+pages[i]<=l)
                {
                    sc[j].push_back(pages[i]);
                    u+=pages[i];
                    sum-=pages[i];
                }
                else
                {
                    b=i+1;
                    u=0;
                    break;
                }
            }
        }
        for(int i=1;i<=k;i++)
        {
            int siz=sc[i].size();
            for(int j=siz-1;j>=0;j--)
                printf("%i ", sc[i][j]);
            sc[i].clear();
            if(i!=k) printf("/ ");
        }
        printf("\n");

    }
}
