#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch1, ch2;
    int br1, br2, n, c=0;
    cin.get(ch1);
    cin >> br1;
    cin.get();
    cin.get(ch2);
    cin >> br2;
    br1+=1000*ch1;
    br2+=1000*ch2;
    cin >> n;
    cin.get();
    char cumir[n];
    int brumir[n];
    for(int i=0;i<n;i++)
    {
        cin.get(cumir[i]);
        cin >> brumir[i];
        cin.get();
        brumir[i] += 1000*cumir[i];
    }

    for(int i=br1; i<=br2;i++)
    {
        c++;
        for(int j=0;j<n;j++)
            if(brumir[j]==i) c--;
    }
    cout << c << endl;
}
