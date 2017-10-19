#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string stanice[n];
    int k[n], hh, mm, ss, a, pt, pts;
    int dod;
    vector<int> auti;
    vector<pair<int, string> > time[50];
    pair<int, string> temp;

    for(int i=0;i<n;i++)
    {
        cin >> stanice[i];
        cin >> k[i];
        for(int j=0;j<k[i];j++)
        {
            dod=-1;
            cin >> a >> hh;
            cin.get();
            cin >> mm;
            cin.get();
            cin >> ss;
            for(int l=0;l<auti.size();l++)
                if(auti[l]==a) dod=l;
            if(dod==-1) {auti.push_back(a); dod=auti.size()-1;}
            temp.first=hh*3600+mm*60+ss; temp.second=stanice[i];
            time[dod].push_back(temp);
        }
    }

    int mina, mins;
    string st, output, h, m, s;

    for(int b=0;b<50;b++)
    {
        mina=100000000;
        for(int i=0;i<auti.size();i++)
        {
            if(auti[i]<mina) {mina=auti[i]; pt=i;}
        }
        if(mina==100000000) break;
        auti[pt]=100000000;
        for(int c=0;c<time[pt].size();c++)
        {
            mins=100000000;
            for(int i=0;i<time[pt].size();i++)
            {
                if(time[pt][i].first<mins) {mins=time[pt][i].first; st=time[pt][i].second; pts=i;}
            }
            time[pt][pts].first=100000000;
            hh=mins/3600;
            mm=(mins-3600*hh)/60;
            ss=mins-3600*hh - 60*mm;
            if(output.length()>0) output.append(" -> ");
            h=static_cast<ostringstream*>( &(ostringstream() << hh) )->str();
            m=static_cast<ostringstream*>( &(ostringstream() << mm) )->str();
            s=static_cast<ostringstream*>( &(ostringstream() << ss) )->str();
            if(h.length()==1) h.insert(0, "0");
            if(m.length()==1) m.insert(0, "0");
            if(s.length()==1) s.insert(0, "0");
            output.append(st+" "+h+":"+m+":"+s);
        }
        printf("%i %s\n", mina, output.c_str());
        output="";
    }
}
