/*
ID: lbenc131
PROG: sprime
LANG: C++
*/
#include <cstdio>
#include <cmath>
using namespace std;

int len;
FILE *fin, *fout;

int numLen(int n)
{
    int l=0;
    while(n) {n/=10; l++;}
    return l;
}

bool isPrime(int n)
{
    int s=sqrt(n);
    for(int i=2;i<=s;i++)
        if(n%i==0) return false;
    return true;
}

void findPrimes(int n)
{
    if(numLen(n)==len) fprintf(fout, "%i\n", n);
    else if(numLen(n)<len)
    {
        for(int i=0;i<=9;i++)
            if(isPrime(n*10+i)) findPrimes(n*10+i);
    }
}

int main() {
    fin  = fopen ("sprime.in", "r");
    fout = fopen ("sprime.out", "w");

	fscanf(fin, "%i", &len);
    findPrimes(2); findPrimes(3); findPrimes(5); findPrimes(7);

    return 0;
}
