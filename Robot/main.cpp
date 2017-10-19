#include <iostream>
#include <string>
using namespace std;

int main()
{
    int v,s;
    cin >> v >> s;
    int x, y, xx, yy;
    cin >> x >> y;
    string smjer, ssmjer;
    cin >> smjer;
    int n;
    cin >> n;
    long t[n];
    for(int i=0;i<n;i++)
        cin >> t[i];

    for(int i=0;i<n;i++)
    {
        xx=x; yy=y;
        ssmjer=smjer;
        while(t[i]>0)
        {
            if((ssmjer=="UU" && yy<v) || (ssmjer=="DD" && yy==1)) {yy++; ssmjer="UU";}
            else if((ssmjer=="DD" && yy>1) || (ssmjer=="UU" && yy==v)) {yy--; ssmjer="DD";}
            else if((ssmjer=="RR" && xx<s) || (ssmjer=="LL" && xx==1)) {xx++; ssmjer="RR";}
            else if((ssmjer=="LL" && xx>1) || (ssmjer=="RR" && xx==s)) {xx--; ssmjer="LL";}

            else if((ssmjer=="RU" && yy<v && xx<s) || (ssmjer=="LD" && yy==1 && xx==1) || (ssmjer=="RD" && yy==1 && xx<s) || (ssmjer=="LU" && yy<v && xx==1)) {yy++;xx++; ssmjer="RU";}
            else if((ssmjer=="RD" && yy>1 && xx<s) || (ssmjer=="LU" && yy==v && xx==1) || (ssmjer=="RU" && yy==v && xx<s) || (ssmjer=="LD" && yy>1 && xx==1)) {yy--;xx++; ssmjer="RD";}
            else if((ssmjer=="LD" && yy>1 && xx>1) || (ssmjer=="RU" && yy==v && xx==s) || (ssmjer=="LU" && yy==v && xx>1) || (ssmjer=="RD" && yy>1 && xx==s)) {yy--;xx--; ssmjer="LD";}
            else if((ssmjer=="LU" && yy<v && xx>1) || (ssmjer=="RD" && yy==1 && xx==s) || (ssmjer=="LD" && yy==1 && xx>1) || (ssmjer=="RU" && yy<v && xx==s)) {yy++;xx--; ssmjer="LU";}

            t[i]--;
        }
        cout << xx << " " << yy << endl;
    }
}
