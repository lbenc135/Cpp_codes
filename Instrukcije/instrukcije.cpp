#include <iostream>
using namespace std;

int main()
{
    int a1=0;
    int b1=0;
    cin >> a1;
    cin >> b1;
    int sum=0;
    int ni=0;
    int numbers[1000];
    for(int nb=1;ni<1000;nb++)
    {
        for(int j=0;j<nb && ni<1000;j++)
        {
            numbers[ni]=nb;
            ni++;
        }
    }
    if(a1 == b1)
        cout << numbers[a1-1] << endl;
    else
    {
        for(a1;a1<=b1;a1++)
            sum+=numbers[a1-1];
        cout << sum;
    }
}
