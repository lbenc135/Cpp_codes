#include <algorithm>
#include <cstdio>
using namespace std;

#define NMAX 32768
#define TMAX 65536

char niz[NMAX];
struct cvor
{
    int sum, minsum;
} Tree[TMAX];

void inicijalizacija(int cvor, int i, int j)
{
    if(i==j)
    {
        if(niz[i]=='(')
        {
            Tree[cvor].sum = 1;
            Tree[cvor].minsum =1;
        }
        else
        {
            Tree[cvor].sum = -1;
            Tree[cvor].minsum =-1;
        }
        return;
    }

    int m = (i+j)/2;
    inicijalizacija(2*cvor, i, m);
    inicijalizacija(2*cvor+1, m+1, j);
    Tree[cvor].sum = Tree[2*cvor].sum + Tree[2*cvor+1].sum;
    Tree[cvor].minsum = min(Tree[2*cvor].minsum, Tree[2*cvor].sum + Tree[2*cvor+1].minsum);
}

void update(int cvor, int i, int j, int k)
{
    if(i==j)
    {
        Tree[cvor].sum = Tree[cvor].minsum = -Tree[cvor].sum;
        return;
    }
    int m = (i+j)/2;
    if(k<=m)
        update(2*cvor, i, m, k);
    else
        update(2*cvor+1, m+1, j, k);
    Tree[cvor].sum = Tree[2*cvor].sum + Tree[2*cvor+1].sum;
    Tree[cvor].minsum = min(Tree[2*cvor].minsum, Tree[2*cvor].sum + Tree[2*cvor+1].minsum);
}

int main()
{
    int N, M, i, k, test = 1;
    while(test<=10)
    {
        scanf("%d", &N);
        scanf("%s", niz);
        inicijalizacija(1, 0, N-1);
        printf("Test %d:\n", test++);
        scanf("%d", &M);
        for(i=0; i<M; i++)
        {
            scanf("%d", &k);
            if(k==0)
            {
                if(Tree[1].sum==0 && Tree[1].minsum==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                update(1, 0, N-1, k-1);
        }
    }
    return 0;
}
