#include <cstdio>
#include <iostream>
using namespace std;

bool nikola[31];

void init(int p)
{
    for(int i=2;i<=30;i++)
    {
        p%=7;
        p++;
        if(p==6 || p==7 || !(i%2)) nikola[i]=1;
    }
}

int main()
{
    string dan;
    cin >> dan;
    if(dan=="pon")
        init(1);
    else if(dan=="uto")
        init(2);
    else if(dan=="sri")
        init(3);
    else if(dan=="cet")
        init(4);
    else if(dan=="pet")
        init(5);

    int m, t;
    scanf("%i", &m);
    for(int i=0;i<m;i++)
    {
        scanf("%i", &t);
        nikola[t]=0;
    }

    int nik=0;
    for(int i=1;i<=30;i++)
        nik+=nikola[i];
    printf("%i %i", nik, 30-nik);
}
