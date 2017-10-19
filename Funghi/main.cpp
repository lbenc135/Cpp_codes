#include <cstdio>
using namespace std;

int main()
{
    int s[8];
    for(int i=0;i<8;i++)
        scanf("%i", &s[i]);

    int maxs=0, temp;
    for(int i=0;i<8;i++)
    {
        temp=0;
        for(int j=i;j<i+4;j++)
        {
            temp+=s[j%8];
        }
        if(temp>maxs) maxs=temp;
    }

    printf("%i\n", maxs);

}
