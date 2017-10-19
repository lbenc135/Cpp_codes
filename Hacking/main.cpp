#include <cstdio>
using namespace std;

#define BASE 1337
#define ull unsigned long long

int n, m, k;
char pub[10001], word[101];

ull b[10001]={1};
ull hashpub[10001];
ull hw;

ull hashWord()
{
    ull hashW=0;
    for(int i=0;i<m;i++)
        hashW+=word[i]*b[i];
    return hashW;
}

bool createWord(int s)
{
    if(s==0)
    {
        if(hw==hashpub[m-1]) return false;
        for(int i=m;i<n;i++)
            if(hw*b[i-m+1]==hashpub[i]-hashpub[i-m]) return false;
        return true;
    }

    for(int i=0;i<k;i++)
    {
        if(word[m-s]!=0)
            hw-=word[m-s]*b[m-s];

        word[m-s]=i+'a';
        hw+=word[m-s]*b[m-s];

        if(createWord(s-1)) return true;
    }
    return false;
}

void createHashes()
{
    for(int i=0;i<n;i++)
    {
        if(i)
            hashpub[i]=hashpub[i-1]+pub[i]*b[i];
        else
            hashpub[i]=pub[i];
    }
}

void initBase()
{
    for(int i=1;i<10001;i++)
        b[i]=b[i-1]*BASE;
}

int main()
{
    initBase();

    int t;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i %i %i", &n, &m, &k);
        scanf("%s", &pub);

        createHashes();
        createWord(m);

        printf("%s\n", word);

        for(int i=0;i<m;i++)
            word[i]=0;
        hw=0;
    }
}
