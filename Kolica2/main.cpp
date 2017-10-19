#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x[n], y[n];
    string smjer[n];
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i] >> smjer[i];

    vector<long long> kol1, kol2;
    vector<double> time;
    int low;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(smjer[i]==smjer[j]) continue;
            if((smjer[i]=="gore" && smjer[j]=="dolje" && x[i]==x[j] && y[i]<y[j]) || (smjer[i]=="dolje" && smjer[j]=="gore" && x[i]==x[j] && y[i]>y[j]))
                {low=lower_bound(time.begin(), time.end(), abs(y[j]-y[i])/2.0)-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(y[j]-y[i])/2.0);}
            else if(smjer[i]=="dolje" && smjer[j]=="lijevo" && x[j]>x[i] && y[i]>y[j] && x[j]-x[i]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="lijevo" && smjer[j]=="dolje" && x[j]<x[i] && y[i]<y[j] && x[j]-x[i]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="dolje" && smjer[j]=="desno" && x[j]<x[i] && y[i]>y[j] && x[i]-x[j]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="desno" && smjer[j]=="dolje" && x[j]>x[i] && y[i]<y[j] && x[i]-x[j]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if((smjer[i]=="lijevo" && smjer[j]=="desno" && y[i]==y[j] && x[i]>x[j]) || (smjer[i]=="desno" && smjer[j]=="lijevo" && y[i]==y[j] && x[i]<x[j]))
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i])/2.0)-time.begin(); kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i])/2.0);}
            else if(smjer[i]=="lijevo" && smjer[j]=="gore" && x[j]<x[i] && y[i]>y[j] && x[i]-x[j]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="gore" && smjer[j]=="lijevo" && x[j]>x[i] && y[i]<y[j] && x[i]-x[j]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="desno" && smjer[j]=="gore" && x[j]>x[i] && y[i]>y[j] && x[j]-x[i]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
            else if(smjer[i]=="gore" && smjer[j]=="desno" && x[j]<x[i] && y[i]<y[j] && x[j]-x[i]==y[i]-y[j])
                {low=lower_bound(time.begin(), time.end(), abs(x[j]-x[i]))-time.begin();  kol1.insert(kol1.begin()+low, i); kol2.insert(kol2.begin()+low, j); time.insert(time.begin()+low, abs(x[j]-x[i]));}
        }

    double sec=0;
    int kolica[n];
    for(int i=0;i<n;i++)
        kolica[i]=-1;
    for(int i=0;i<time.size();i++)
    {
        if(sec!=time[i]) sec=time[i];
        if(kolica[kol1[i]]==-1 && kolica[kol2[i]]==-1) {kolica[kol1[i]]=sec; kolica[kol2[i]]=sec;}
        else if((kolica[kol1[i]]==-1 && sec==kolica[kol2[i]]) || (kolica[kol2[i]]==-1 && sec==kolica[kol1[i]])) {kolica[kol1[i]]=kolica[kol2[i]]=sec;}
    }

    bool nema=true;
    for(int i=0;i<n;i++)
    {
        if(kolica[i]==-1) {cout << i+1 << endl; nema=false;}
    }
    if(nema) cout << "nema" << endl;

    return 0;
}
