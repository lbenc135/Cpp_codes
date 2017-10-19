#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  int masa, uteg=1;

  vector <int> rjesenje;

  cin>>masa;

  while(masa)
  {
       /*pohlepni pristup - prvo nađemo najvecu potenciju broja 3 s kojom je
        masa djeljiva (zato ova prazna naredba)*/
      if(masa % (uteg*3) == 0) ;
        /*ispitamo: ako dodamo uteg na drugu stranu vage, hoce li onda biti
         djeljiva sa sljedecim utegom (potencijom od broja 3)*/
      else if(masa % (uteg*3) == uteg)
      {
           /*u slucaju da hoce, oduzmemo od trazene mase uteg te taj uteg
           dodamo u rjesenje*/
        masa = masa - uteg;
        rjesenje.push_back(uteg);
      }
        else
        {
             /*u slucaju da nece, taj uteg dodamo na masu i stavimo u rjesenje
              s negativnim predznakom*/
           masa = masa + uteg;
           rjesenje.push_back(-uteg);
        }
      uteg = uteg * 3;
      }

  sort(rjesenje.begin(), rjesenje.end());


  vector<int>::iterator it;
  for ( it=rjesenje.begin() ; it < rjesenje.end(); it++ )
    cout << *it<<" ";

   cout<<endl;



  return 0;
}
