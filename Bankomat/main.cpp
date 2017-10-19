#include <iostream>
#include <vector>
using namespace std;

class korisnik {
    public:
        string ime, lozinka;
        int iznos=0;
        korisnik() {}
        korisnik(string i, string l)
        {
            ime = i;
            lozinka = l;
        }

        void uplati(int x)
        {
            iznos+=x;
            cout << endl << "Polozeno " << x << " kuna na racun." << endl;
        }

        void isplati(int x)
        {
            if(iznos>=x)
            {
                iznos-=x;
                cout << endl << "Isplaceno " << x << " kuna s racuna." << endl;
            }
            else
            {
                cout << endl << "Na racunu nema dovoljno sredstava za isplatu " << x << " kuna. Molim unesite " << iznos << " ili manje kuna." << endl;
            }
        }
};

int main()
{
    vector<korisnik> korisnici;

    korisnici.push_back(korisnik("Anica", "anica123"));
    korisnici.push_back(korisnik("Slavko", "slavkec1"));
    korisnici.push_back(korisnik("Jurica", "123456"));

    while(1)
    {
        int aktivan=-1, kod=0, iznos;

        cout << endl << "Prijava na sustav:" << endl;
        cout << "Unesite svoje ime i lozinku odvojene razmakom: ";
        string ime, lozinka;
        cin >> ime >> lozinka;

        for(int i=0;i<korisnici.size();i++)
            if(korisnici[i].ime==ime && korisnici[i].lozinka==lozinka) aktivan=i;

        if(aktivan==-1)
            cout << endl << "Prijava nije uspjela. Molim pokusajte ponovo." << endl;
        else
        {
            cout << "Prijava uspjesna!" << endl;
            do
            {
                cout << "Trenutno stanje racuna: " << korisnici[aktivan].iznos << endl;
                cout << "Za uplatu na racun odaberite 1 , za isplatu 2, a za izlaz -1: ";
                cin >> kod;
                switch(kod)
                {
                case 1:
                    cout << endl << "Iznos: ";
                    cin >> iznos;
                    korisnici[aktivan].uplati(iznos);
                    break;
                case 2:
                    cout << endl << "Iznos: ";
                    cin >> iznos;
                    korisnici[aktivan].isplati(iznos);
                    break;
                }
            } while(kod!=-1);
        }

    }
}
