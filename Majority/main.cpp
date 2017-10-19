#include <cstdio>
#include <map>
using namespace std;

map<int,int> data;

int main()
{
    int t;
    scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        int n, n2;
        scanf("%i", &n);
        n2=n/2;
        int temp, good = -1;
        for(int i=0;i<n;i++) {
            scanf("%i", &temp);
            data[temp]++;
            if(data[temp]>n2)
                good = temp;
        }
        if(good != -1)
            printf("YES %i\n", good);
        else
            printf("NO\n");
        data.clear();
    }
}
