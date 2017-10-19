#include <iostream>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    int golova1=x1+x2, golova2=y1+y2;
    if(golova1==golova2)
      {cin >> x3 >> y3;
      golova1+=x3; golova2+=y3;}
    if(golova1==golova2)
      {cin >> x4 >> y4;
      golova1+=x4; golova2+=y4;}
    int golova=golova1+golova2;
    if(golova1>golova2) cout << "domacin" << endl << golova;
    else cout << "gost" << endl << golova;
}
