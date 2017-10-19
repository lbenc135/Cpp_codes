#include <cstdio>
#include <iostream>
using namespace std;

char mat[5][5];
bool slova[26];

int red, stup;

void popuni(string kljuc)                           // Popunjavanje matrice za kriptiranje
{
    int x=0, y=0;
    for(int i=0;i<kljuc.length();i++)
    {
        if(!slova[kljuc[i]-'A'])
        {
            slova[kljuc[i]-'A']=1;
            mat[x][y]=kljuc[i];
            x++;
        }
        if(x>=5)
        {
            x=0; y++;
        }
    }
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            if(!mat[j][i])
            {
                for(int k=0;k<26;k++)
                    if(k=='J'-'A') continue;        // 'J' ako su I i J u istoj celiji, 'W' ako su V i W
                    else if(!slova[k])
                    {
                        mat[j][i]=k+'A';
                        slova[k]=1;
                        break;
                    }
            }
        }
}

void nadiredistup(char c)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(mat[j][i]==c)
            {
                stup=j; red=i;
                return;
            }
}

int main()
{
    string kljuc, f;
    cin >> f >> kljuc;
    FILE *dat = fopen(f.c_str(), "r");

    popuni(kljuc);

    if(dat==NULL) cout << "Greska u otvaranju!";
    else
    {
        FILE *out = fopen(f.insert(0, "sifrirano_").c_str(), "w");

        bool uc2=true;
        while(!feof(dat))
        {
            char c1, c2, temp;
            if(fscanf(dat, "%c", &c1)<=0) return 0;                     // Ako feof nije nasao EOF, a nema vise znakova za ucitati, zavrsi program
            if(uc2)
            {
                if(fscanf(dat, "%c", &c2)<=0) c2='X';
            }
            else
            {
                uc2=1;
                c1=temp;
                fscanf(dat, "%c", &c2);
            }
            if(c1==c2)                                                  // Ako su ucitana dva ista slova
            {
                temp=c2;                                                // Spremi drugo slovo i zamijeni ga s X
                c2='X';
                uc2=0;                                                  // U sljedecoj iteraciji ucitaj samo jedno slovo, a kao prvo uzmi ono koje je zamijenjeno s X-om
            }
            if(c1>='A' && c1<='Z' && c2>='A' && c2<='Z')
            {
                int r1, s1, r2, s2;                                     // Nadi redove i stupce slova u matrici
                nadiredistup(c1);
                r1=red; s1=stup;
                nadiredistup(c2);
                r2=red; s2=stup;

                if(r1==r2)
                {
                    c1=mat[(s1+1)%5][r1];
                    c2=mat[(s2+1)%5][r2];
                }
                else if(s1==s2)
                {
                    c1=mat[s1][(r1+1)%5];
                    c2=mat[s2][(r2+1)%5];
                }
                else
                {
                    c1=mat[s2][r1];
                    c2=mat[s1][r2];
                }

                if(out!=NULL) fprintf(out, "%c%c", c1, c2);
            }
        }
        fclose(dat);
        if(out!=NULL) fclose(out);
    }

    return 0;
}
