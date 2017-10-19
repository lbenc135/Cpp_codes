#include <cstdio>
#include <list>
using namespace std;

long long abs(long long x);

int main()
{
    long long a, b;
    int q;
    scanf("%lli %lli %i", &a, &b, &q);
    list<long long> qs;
    long long s0=a, s1=b, st, qst;
    for(int i=0;i<q;i++)
    {
        scanf("%lli", &qst);
        qs.push_back(qst);
    }

    list<long long>::iterator it=qs.begin();
    if(*it==0)
    {
        printf("%lli\n", a);
        it++;
    }
    if(*it==1)
    {
        printf("%lli\n", b);
        it++;
    }
    for(long long i=2;it!=qs.end();i++)
    {
        st=abs(s0-s1);
        if(*it==i)
        {
            printf("%lli\n", st);
            it++;
        }
        s0=s1;
        s1=st;
    }
}

long long abs(long long x)
{
    return x<0?-x:x;
}
