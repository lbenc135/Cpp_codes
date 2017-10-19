#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        int n;
        scanf("%i", &n);
        int men[1001]={0}, women[1001]={0};
        for(int i=0;i<n;i++)
            scanf("%i", &men[i]);
        for(int i=0;i<n;i++)
            scanf("%i", &women[i]);

        sort(men, men+n);
        sort(women, women+n);

        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=men[i]*women[i];
        }
        printf("%li\n", sum);
    }
}
