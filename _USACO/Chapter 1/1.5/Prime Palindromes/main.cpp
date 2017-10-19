/*
ID: lbenc131
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;

bool isPrime(int a)
{
    int s=sqrt(a);
    for(int i=2;i<=s;i++)
        if(a%i==0) return false;
    return true;
}

int main() {
    FILE *fin  = fopen ("pprime.in", "r");
    FILE *fout = fopen ("pprime.out", "w");

	int a, b;
    fscanf(fin, "%i %i", &a, &b);

    for(int i=5;i<=9;i+=2)
        if(i>=a && i<=b && isPrime(i)) v.push_back(i);
    for(int i=1;i<=9;i+=2)
    {
        int n=10*i+i;
        if(n>=a && n<=b && isPrime(n)) v.push_back(n);
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            int n=100*i+10*j+i;
            if(n>=a && n<=b && isPrime(n)) v.push_back(n);
        }
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            int n=1000*i+100*j+10*j+i;
            if(n>=a && n<=b && isPrime(n)) v.push_back(n);
        }
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int n=10000*i+1000*j+100*k+10*j+i;
                if(n>=a && n<=b && isPrime(n)) v.push_back(n);
            }
        }
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int n=100000*i+10000*j+1000*k+100*k+10*j+i;
                if(n>=a && n<=b && isPrime(n)) v.push_back(n);
            }
        }
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    int n=1000000*i+100000*j+10000*k+1000*l+100*k+10*j+i;
                    if(n>=a && n<=b && isPrime(n)) v.push_back(n);
                }
            }
        }
    }
    for(int i=1;i<=9;i+=2)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    int n=10000000*i+1000000*j+100000*k+10000*l+1000*l+100*k+10*j+i;
                    if(n>=a && n<=b && isPrime(n)) v.push_back(n);
                }
            }
        }
    }

    for(int i=0;i<v.size();i++)
        fprintf(fout, "%i\n", v[i]);

    return 0;
}
