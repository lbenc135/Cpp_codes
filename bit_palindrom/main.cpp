#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%i", &n);

    int zadnja_jedinica = log2(n);
    int n_rev=0;
    for(int i=zadnja_jedinica;i>=0;i--)
    {
        if(n & 1<<i) n_rev+=1<<(zadnja_jedinica-i);
    }

    if(n==n_rev)
        printf("Palindrom je u binarnom!\n");
    else
        printf("Nije palindrom u binarnom!\n");
}
