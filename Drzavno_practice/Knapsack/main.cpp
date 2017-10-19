#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

#define weight first
#define value second

int n;
pair<int,int> obj[10];
int stanje[100];

int knapsack(int c)
{
    if(stanje[c]!=-1) return stanje[c];

    int maks=0;
    for(int i=0;obj[i].weight<=c && i<n;i++)
    {
        if(knapsack(c - obj[i].weight) + obj[i].value > maks)
            maks = knapsack(c - obj[i].weight) + obj[i].value;
    }
    return stanje[c]=maks;
}

int main()
{
    int c;
    scanf("%i %i", &c, &n);
    for(int i=0;i<n;i++)
        scanf("%i %i", &obj[i].weight, &obj[i].value);

    sort(obj, obj+n);
    memset(stanje, -1, sizeof(stanje));
    printf("%i\n", knapsack(c));
}
