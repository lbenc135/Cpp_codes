#include <iostream>
using namespace std;

int main()
{
    int cuts;
    cin >> cuts;
    cout << (cuts/2+1)*(cuts-cuts/2+1);
}
