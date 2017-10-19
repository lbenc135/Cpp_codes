#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    string arr[50];
    int i=-1;
    cout << "Napisi max 50 stvari. Za kraj unosa upisi '...' (bez navodnika)!" << endl;
    do
    {
        i++;
        cin >> arr[i];
    } while(arr[i]!="...");

    srand (time(NULL));
    cout << endl << "Random input: " << arr[rand()%i] << endl << endl;

    system("PAUSE");
}
