#include <cstdio>
#include <cmath>
using namespace std;

void findFirstPrimes(int n);

int firstPrimes[100001];
int numPrimes;

int main()
{
    int t, n, m, diff;
    scanf("%i", &t);
    for(int tc=0;tc<t;tc++)
    {
        scanf("%i %i", &n, &m);

        diff = m-n;
        bool primes[100001];
        for(int i=0;i<100001;i++)
            primes[i]=true;

        findFirstPrimes(m);

        for(int i=0;i<numPrimes;i++)
        {
            int p = firstPrimes[i];
            int s = n/p;
            s*=p;
            if(s<n) s+=p;
            for(int j=s;j<=m;j+=p)
                primes[j-n]=false;
        }

        for(int i=0;i<numPrimes;i++)
            if(firstPrimes[i]>=n && firstPrimes[i]<=m)
                printf("%i\n", firstPrimes[i]);

        for(int i=0;i<=diff;i++)
            if(primes[i]==true && (i+n)!=1)
                printf("%i\n", i+n);
        printf("\n");

        numPrimes=0;
    }
}

void findFirstPrimes(int n)
{
    bool primes[100001];
    int range = int(sqrt((double)n)+0.5);
    for(int i=2;i<100001;i++)
        primes[i]=true;

    int k = int(sqrt((double)range)+0.5);
    for(int i=2;i<=k;i++)
        if(primes[i]==true)
            for(int j=i*i;j<=range;j+=i)
                primes[j]=false;

    for(int i=2;i<=range;i++)
        if(primes[i]==true)
            firstPrimes[numPrimes++]=i;
}
