#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, m, k;
    int vals[51], val, uk;
    char temp[1];
    scanf("%i", &t);
    while(t--)
    {
        uk=0;
        scanf("%i %i %i", &n, &m, &k);
        for(int i=0;i<n;i++)
        {
            val=0;
            for(int j=0;j<m;j++)
            {
                scanf(" %c", &temp);
                if(temp[0]=='*') val++;
            }
            vals[i]=val;
            uk+=val;
        }
        for(int i=0;i<k;i++)
        {
            sort(vals, vals+n);
            uk-=vals[0];
            vals[0]=m-vals[0];
            uk+=vals[0];
        }
        printf("%i\n", uk);
    }
}
