#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

#define pii pair<int,int>

pii film[3];
char naz[3][20]={"Prstenova druzina", "Dvije kule", "Povratak kralja"};

int main()
{
    int d, e;
    scanf("%i %i %i %i %i", &film[0].first, &film[1].first, &film[2].first, &d, &e);
    film[0].second=0; film[1].second=1; film[2].second=2;

    sort(film, film+3);
    film[0].first+=d;
    film[2].first+=e;
    sort(film, film+3);

    for(int i=2;i>=0;i--)
        printf("%s\n", naz[film[i].second]);
}
