#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,d,temp;
    cin >> n >> d;
    vector<int> p;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    int k, krugova=0, krug=0;
    cin >> k;
    int r[k];
    for(int i=0;i<k;i++)
        cin >> r[i];

    int po;
    while(p[0]!=0)
    {
        po=0;
        for(int i=0;i<r[krug];i++)
        {
            if(po>=p.size())
                break;
            if(po<p.size())
                p[po]-=d;
            if(p[po]<=0)
            {
                if(p.size()>1)
                    p.erase(p.begin()+po);
                else
                {
                    p[0]=0;
                    break;
                }
                po--;
            }
            po++;
        }
        krug++;krugova++;
        if(krug==k) krug=0;
    }
    cout << krugova;
}
