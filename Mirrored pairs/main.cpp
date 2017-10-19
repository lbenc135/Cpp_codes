#include <iostream>

using namespace std;

int main()
{
    string a;
    cout << "Ready\n";
    while(true) {
        getline(cin, a);
        if(a=="  ") break;

        if(a=="qp" || a=="pq" || a=="db" || a=="bd")
            cout << "Mirrored pair\n";
        else
            cout << "Ordinary pair\n";
    }
}
