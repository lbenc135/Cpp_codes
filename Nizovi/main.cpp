#include <iostream>
#include <vector>
using namespace std;

void makenumbers();
bool bs(long long x);

vector<long long> drugi;
long long a, b, c, d;

int main()
{
    vector<long long> rj;
    cin >> a >> b >> c >> d;
    long long temp=a;
    drugi.push_back(c);
    while(rj.size()<3)
    {
        if(bs(temp)) rj.push_back(temp);
        temp+=b;
        if(bs(temp)) rj.push_back(temp);
        temp+=a;
    }
    for(int i=0;i<3;i++)
        cout << rj[i] << endl;
}

void makenumbers()
{
    for(int i=0;i<10;i++)
    {
        drugi.push_back(drugi.back()+d);
        drugi.push_back(drugi.back()+c);
    }
}

bool bs(long long x)
{
    long long low=0, high=drugi.size(), mid;
    while(x>drugi.back()) {makenumbers(); high+=20;}
    do
    {
        mid=(low+high)/2;
        if(drugi[mid]<x) low=mid;
        else if(drugi[mid]>x) high=mid;
        else return true;
    } while(low<high-1);
    return false;
}
