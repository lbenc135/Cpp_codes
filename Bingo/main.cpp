#include <cstdio>
using namespace std;

int abs(int x);

int main()
{
    int n, b;
    while(true)
    {
        scanf("%i %i", &n, &b);
        if(n==0 && b==0) break;
        int balls[92];
        for(int i=0;i<b;i++)
            scanf("%i", &balls[i]);

        bool ns[92] = {true, false};
        for(int i=0;i<b-1;i++)
            for(int j=i+1;j<b;j++)
            {
                ns[abs(balls[i]-balls[j])] = true;
            }
        bool can = true;
        for(int i=0;i<=n;i++)
            if(ns[i]==false) can = false;
        if(can)
            printf("Y\n");
        else
            printf("N\n");
    }
}

int abs(int x)
{
    return x<0?-x:x;
}
