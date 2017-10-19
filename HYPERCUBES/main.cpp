#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

string brzo_pot(string a, int n);
string karatsuba(string a, string b);
string multiply(const string &a, const string &b);
string zbrstr(string n, string z);
string strsub(string n, string z);

int main()
{
    int t=2000, i=100;
    char n[10002]={'1','0', '0'};
    //scanf("%i", &t);
    for(int c=0;c<t;c++)
    {
        //scanf("%s %i", &n, &i);
        string rez1 = brzo_pot(string(n), i);
        string rez2 = brzo_pot(strsub(string(n), "2"), i);
        printf("%s\n", strsub(rez1, rez2).c_str());
    }
}

string brzo_pot(string a, int n)
{
    string x="1";
    int q, r;

    q=n/2; r=n%2;
    while(true)
    {
        if(r==1) x=karatsuba(x, a);
        if(q==0) break;
        n=q;
        a=karatsuba(a, a);
        q=n/2; r=n%2;
    }

    return x;
}

string karatsuba(string a, string b)
{
    int la=a.length(), lb=b.length();
    if(la<32 || lb<32)
        return multiply(a, b);
    else
    {
        int k = min(la, lb)/2;
        string a0 = a.substr(0, la-k);
        string a1 = a.substr(la-k, k);
        string b0 = b.substr(0, lb-k);
        string b1 = b.substr(lb-k, k);
        string an = karatsuba(a0, b0);
        string cn = karatsuba(a1, b1);
        string temp0 = zbrstr(a0, a1),
        temp1 = zbrstr(b0, b1),
        temp2 = karatsuba(temp0, temp1),
        temp3 = zbrstr(an, cn);
        string bn = strsub(temp2, temp3);
        an.insert(an.length(), k*2, '0');
        bn.insert(bn.length(), k, '0');
        string temp4 = zbrstr(an, cn);
        return zbrstr(temp4, bn);
    }
}

string multiply(const string &a, const string &b)
{
  /* initially fill the result string with 0's */
  size_t total_len= a.length() + b.length();
  string result(total_len, '0');

  int num;                                      /* intermediate store */
  int i, j;
  int last_pos_i, last_pos_j, last_pos_k;

  last_pos_i= total_len - 1;

  /* i-loop */
  for (i= b.length() - 1; i >= 0; i --)
  {
    last_pos_j= last_pos_i;

    /* j-loop */
    for (j= a.length() - 1; j >=0; j --)
    {
      last_pos_k= last_pos_j;
      num= (a[j]-'0') * (b[i]-'0');

      /* k-loop : the actual updation of result string takes place here. */
      while (num)
      {
        num += result[last_pos_k]-'0';
        result.at(last_pos_k)= num % 10 + '0';
        /* 'carry' it forward.. ;)  */
        num= num / 10;
        last_pos_k --;
      }

      last_pos_j --;
    }

    last_pos_i --;
  }
  for(int i=0;i<result.length();i++)
        if(result[i]=='0') result.erase(i, 1);
        else break;
  return result;
}

string zbrstr(string n, string z)
{
    string rez, temp;
    if(n.length()<z.length())
    {
        temp=n;
        n=z;
        z=temp;
    }
    int pt1, pt2, zn, dalje=0;
    for(int i=1;pt2>0;i++)
    {
        pt1=n.length()-i;
        pt2=z.length()-i;
        zn=n[pt1]-'0' + z[pt2]-'0' + dalje;
        if(zn>9)
        {
            zn-=10;
            dalje=1;
        }
        else dalje=0;
        rez.insert(0, 1, (zn+'0'));
    }
    pt1--;
    while(dalje)
    {
        if(pt1<0) {
            rez.insert(0, 1, '1');
            dalje=0;
        }
        else if(n[pt1]=='9') {
            n[pt1]='0';
            rez.insert(0, 1, '0');
            pt1--;
        }
        else {
            n[pt1]+=dalje;
            dalje=0;
        }
    }
    while(pt1>=0)
    {
        rez.insert(0, 1, n[pt1]);
        pt1--;
    }
    return rez;
}

string strsub(string n, string z)
{
    string rez, temp;
    int nlen = n.length(), zlen = z.length();
    if(nlen<zlen || (nlen==zlen && n[0]<z[0]))
    {
        temp=n;
        n=z;
        z=temp;
    }
    int zn, dalje=0;
    int pt1 = n.length()-1, pt2 = z.length()-1;
    while(pt2>=0)
    {
        if(n[pt1]>=z[pt2]+dalje)
        {
            zn=n[pt1] - z[pt2] - dalje;
            dalje=0;
        }
        else
        {
            zn=10-(z[pt2]+dalje-n[pt1]);
            dalje=1;
        }
        rez.insert(0, 1, char(zn+'0'));
        pt1--; pt2--;
    }
    while(dalje)
    {
        if(n[pt1]-dalje>='0')
        {
            n[pt1]-=dalje;
            dalje=0;
        }
        else
        {
            rez.insert(0, 1, 10-n[pt1]+'0'-dalje+'0');
            pt1--;
        }
    }
    while(pt1>=0)
    {
        rez.insert(0, 1, n[pt1]);
        pt1--;
    }
    for(int i=0;i<rez.length();i++)
        if(rez[i]=='0') rez.erase(i, 1);
        else break;
    return rez;
}
