#include <iostream>
using namespace std;

void clean(int r, int s);

int r, s;
char slika[41][101];

int main()
{
    cin >> r >> s;
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            cin >> slika[i][j];

    for(int i=0;i<s;i++)
        for(int j=0;j<r;j++)
            if(slika[j][i]=='X')
            {
                if(slika[j+1][i]=='X' && slika[j+2][i+1]=='.')
                    {cout << 0; clean(j,i);}
                else if(slika[j+1][i+1]=='X')
                    {cout << 1; clean(j,i); slika[j-1][i+1]='.';}
                else if(slika[j+1][i]=='.' && slika[j+3][i]=='X' && slika[j+2][i]=='X')
                    {cout << 2; clean(j,i);}
                else if(slika[j+1][i]=='.' && slika[j+2][i]=='X' && slika[j+3][i]=='.')
                    {cout << 3; clean(j,i);}
                else if(slika[j][i+1]=='.')
                    {cout << 4; clean(j,i);}
                else if(slika[j+1][i+2]=='.' && slika[j+3][i]=='.')
                    {cout << 5; clean(j,i);}
                else if(slika[j+1][i+2]=='.' && slika[j+3][i]=='X' && slika[j+1][i+1]=='.')
                    {cout << 6; clean(j,i);}
                else if(slika[j+1][i]=='.' && slika[j+2][i+1]=='.')
                    {cout << 7; clean(j,i);}
                else if(slika[j+1][i+2]=='X' && slika[j+3][i]=='X' && slika[j+2][i+1]=='X' && slika[j+1][i]=='X')
                    {cout << 8; clean(j,i);}
                else {cout << 9; clean(j,i);}
            }
}

void clean(int r, int s)
{
    for(int i=r; i<r+5;i++)
        for(int j=s;j<s+3;j++)
            slika[i][j]='.';

}
