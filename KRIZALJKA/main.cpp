#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> input(6);
    int found;
    for(int i=0;i<6;i++)
        cin >> input[i];

    do {
        string stupci[3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                stupci[j] += input[i][j];

        found = 0;
        for(int i=3;i<6;i++)
            if(stupci[i-3]==input[i]) {found++;}

        if(found==3) {cout << endl << input[0] << endl << input[1] << endl << input[2]; break;}
    } while(next_permutation(input.begin(), input.end()));

    if(found==false)
        cout << 0;
}
