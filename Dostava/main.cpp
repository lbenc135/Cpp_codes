#include <algorithm>
#include <iostream>
#include <cmath>

#define MAXN 100000

using namespace std;


int n, k;
long long kumulativna_suma[3][MAXN+2];

long long suma(int ulica, int a, int b)
{
   if(a > b) swap(a, b);
   return kumulativna_suma[ulica][b] - kumulativna_suma[ulica][a];
}

int ulica(int lokacija) {
   if(lokacija == 1 || lokacija == 3*n+2) return 0;
   return (lokacija-2)/n;
}

int redni_broj(int lokacija) {
   if(lokacija == 1) return 0;
   if(lokacija == 3*n+2) return n+1;
   return (lokacija-2)%n + 1;
}

long long najkraci_put(int lokacijaA, int lokacijaB) {
   int uA = ulica(lokacijaA), rbA = redni_broj(lokacijaA);
   int uB = ulica(lokacijaB), rbB = redni_broj(lokacijaB);

   long long ret = 1000000000000000LL;

   // 1) A -> B (uz uvjet da su u istoj ulici)
   if(uA == uB) ret = min(ret, suma(uA, rbA, rbB));

   // 2) A -> lijevi trg -> B
   ret = min(ret, suma(uA, rbA, 0) + suma(uB, 0, rbB));

   // 3) A -> desni trg -> B
   ret = min(ret, suma(uA, rbA, n+1) + suma(uB, n+1, rbB));

   // 4) A -> lijevi trg -> desni trg -> B
   for(int uC = 0; uC < 3; ++uC)
      ret = min(ret, suma(uA, rbA, 0) + suma(uC, 0, n+1) + suma(uB, n+1, rbB));

   // 5) A -> desni trg -> lijevi trg -> B
   for(int uC = 0; uC < 3; ++uC)
      ret = min(ret, suma(uA, rbA, n+1) + suma(uC, n+1, 0) + suma(uB, 0, rbB));

   return ret;
}

int main(void) {
   cin >> n;
   for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < n+1; ++j) {
         int vrijeme;
         cin >> vrijeme;
         kumulativna_suma[i][j+1] = kumulativna_suma[i][j] + vrijeme;
      }
   }

   long long rjesenje = 0;
   int trenutna = 1, sljedeca = 0;

   cin >> k;
   for(int i = 0; i < k; ++i) {
      cin >> sljedeca;

      rjesenje += najkraci_put(trenutna, sljedeca);

      trenutna = sljedeca;
   }
   cout << rjesenje;
}
