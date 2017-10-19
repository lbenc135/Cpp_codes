#include <iostream>
using namespace std;

int main()
{
    string tekst, sifra, stekst;
    cin >> tekst;
    cin >> sifra;

    for(int i=0;i<tekst.length();i++)
    {
        char slovo=(tekst[i]-'A'+sifra[i%sifra.length()]-'A')%26 + 'A';
        stekst.push_back(slovo);
    }
    cout << stekst;
    return 0;
}
