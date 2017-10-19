#include <cstdio>
using namespace std;

int zbrojznamenki(int);

int main()
{
    int n, uktrajanje=0;
    scanf("%i", &n);
    int d[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i", &d[i]);
        uktrajanje+=d[i];
    }


    int sec=2;
    int zbroj=0;
    for(int i=0;i<n;i++)
    {
        zbroj+=zbrojznamenki(sec);
        sec+=d[i];
    }
    printf("%.2x", zbroj%255);

    printf("%.4x", uktrajanje);
    printf("%.2x", n);
}

int zbrojznamenki(int a)
{
    int zbroj=0;
    while(a>0)
    {
        zbroj+=a%10;
        a/=10;
    }
    return zbroj;
}
