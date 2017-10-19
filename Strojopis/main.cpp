#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int prsti[8];

int main()
{
    char str[51];
    scanf("%s", &str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='1' || str[i]=='Q' || str[i]=='A' || str[i]=='Z')
            prsti[0]++;
        else if(str[i]=='2' || str[i]=='W' || str[i]=='S' || str[i]=='X')
            prsti[1]++;
        else if(str[i]=='3' || str[i]=='E' || str[i]=='D' || str[i]=='C')
            prsti[2]++;
        else if(str[i]=='4' || str[i]=='5' || str[i]=='R' || str[i]=='F' || str[i]=='V' || str[i]=='T' || str[i]=='G' || str[i]=='B')
            prsti[3]++;
        else if(str[i]=='6' || str[i]=='7' || str[i]=='Y' || str[i]=='H' || str[i]=='N' || str[i]=='U' || str[i]=='J' || str[i]=='M')
            prsti[4]++;
        else if(str[i]=='8' || str[i]=='I' || str[i]=='K' || str[i]==',')
            prsti[5]++;
        else if(str[i]=='9' || str[i]=='O' || str[i]=='L' || str[i]=='.')
            prsti[6]++;
        else if(str[i]=='0' || str[i]=='P' || str[i]==';' || str[i]=='/' || str[i]=='-' || str[i]=='=' || str[i]=='[' || str[i]==']' || str[i]=='\'')
            prsti[7]++;
    }
    for(int i=0;i<8;i++)
        printf("%i\n", prsti[i]);
}
