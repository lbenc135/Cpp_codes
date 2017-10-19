#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int times;
    cin >> word;
    cin >> times;
    cout << word[((times*word.length())/2)%word.length()] << endl;
}
