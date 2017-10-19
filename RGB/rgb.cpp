#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int colors[3];
    cin >> colors[0] >> colors[1] >> colors[2];
    sort(colors, colors+3);
    cout << (colors[2]-colors[1])+(colors[1]-colors[0]);
}
