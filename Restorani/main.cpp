#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

struct lokacija{int x, y;};
struct neboder{int x, y, st;};

bool visited[100];

bool ispitaj(int x, int y, int x2, int y2, int R)
{
    if(sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))<=R) return true;
    return false;
}

int main()
{
    int r, n, k, m;
    lokacija lokacije[20];
    neboder neboderi[100];
    scanf("%i %i %i", &k, &r, &m);
    for(int i=0;i<m;i++)
        scanf("%i %i", &lokacije[i].x, &lokacije[i].y);
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i %i %i", &neboderi[i].x, &neboderi[i].y, &neboderi[i].st);

    int n2=1<<m, maxi=0;
    for(int i=0;i<n2;i++)
    {
        int ukupno=0, br=0;
        memset(visited, 0, sizeof(visited));
        for(int j=0;j<m;j++)
        {
            if(i & 1<<j)
            {
                for(int l=0;l<n;l++)
                {
                    if(!visited[l] && ispitaj(neboderi[l].x, neboderi[l].y, lokacije[j].x, lokacije[j].y, r))
                    {
                        ukupno+=neboderi[l].st;
                        visited[l]=true;
                    }
                }
                br++;
                if(br>k) {ukupno=0; break;}
            }
        }
        if(ukupno>maxi) maxi=ukupno;
    }
    printf("%i\n", maxi);
}
