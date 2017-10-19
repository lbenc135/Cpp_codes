#include<cstdio>
#include<cstring>
using namespace std;
int main()
{char w[21];for(int i=0;i<10;i++){scanf("%s", &w);int p=0;for(int j=0;j<strlen(w);j++)if(w[j]=='T'||w[j]=='D'||w[j]=='L'||w[j]=='F')p++;printf("%i\n",1<<p);}}
