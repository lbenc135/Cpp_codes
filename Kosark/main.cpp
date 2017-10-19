#include <iostream>
using namespace std;

int abs(int x);

int main()
{
    int n;
    cin >> n;
    int team[101], h[101], m[101], scores[2]={0};
    for(int i=0;i<n;i++) {
        cin >> team[i] >> h[i];
        cin.get();
        cin >> m[i];
    }
    h[n]=48; m[n]=0;

    int h1=0, m1=0, h2=0, m2=0;
    for(int i=0;i<n;i++)
    {
        scores[team[i]-1]++;
        if(scores[0]>scores[1]) {
            int temp1 = h[i]*60+m[i];
            int temp2 = h[i+1]*60+m[i+1];
            int diff = temp2 - temp1;
            h1 += diff/60;
            m1 += diff%60;
        }
        else if(scores[1]>scores[0]) {
            int temp1 = h[i]*60+m[i];
            int temp2 = h[i+1]*60+m[i+1];
            int diff = temp2 - temp1;
            h2 += diff/60;
            m2 += diff%60;
        }
    }

    if(m1>59) {
        h1+=m1/60;
        m1%=60;
    }
    if(m2>59) {
        h2+=m2/60;
        m2%=60;
    }

    if(h1<10) cout << 0;
    cout << h1 << ":";
    if(m1<10) cout << 0;
    cout << m1 << "\n";

    if(h2<10) cout << 0;
    cout << h2 << ":";
    if(m2<10) cout << 0;
    cout << m2 << "\n";
}

int abs(int x)
{
    return x<0?-x:x;
}
