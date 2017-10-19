#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int r, s;
char polje[1001][11];
bool isDeleted[1001];
int h[11];
int nur[1001];

void clearFull()
{
    for(int i=0;i<1001;i++)
        if(nur[i]==s) isDeleted[i]=1;
}

bool isGood()
{
    int maxh, th=0;
    for(int i=0;i<1001;i++)
    {
        if(nur[i] && !isDeleted[i]) maxh=th;
        if(!isDeleted[i]) th++;
    }
    if(maxh<3) return true;
    else return false;
}

void updateData()
{
    memset(h, 0, sizeof(h));
    memset(nur, 0, sizeof(nur));
    for(int i=0;i<1001;i++)
        for(int j=0;j<s;j++)
            if(polje[i][j]=='x' && !isDeleted[i]) { h[j]=i+1; nur[i]++; }
}

int main()
{

    char tempp[11][11];

    scanf("%i %i", &r, &s);
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            scanf(" %c", &tempp[i][j]);
    for(int i=r-1;i>=0;i--)
        for(int j=0;j<s;j++)
            polje[r-i-1][j]=tempp[i][j];

    updateData();

    int n=0;
    vector<int> potezi;
    while(!isGood())
    {
        int mini=1000000000, it=0;
        for(int i=0;i<s;i++)
            if(h[i]<mini) {mini=h[i]; it=i;}
        int th=0;
        for(int i=mini;th<4;i++)
            if(!isDeleted[i])
            {
                nur[i]++;
                polje[i][it]='x';
                th++;
            }

        clearFull();
        updateData();

        n++;
        potezi.push_back(it+1);
    }
    printf("%i\n", n);
    for(int i=0;i<potezi.size();i++)
        printf("%i\n", potezi[i]);
}
