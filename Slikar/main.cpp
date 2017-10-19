#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int  r, s;
char karta[51][51];
int  poplava[51][51];
int  slikar[51][51];

int  potez[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

queue<pair<int, int> > Q;

int main()
{
   memset( poplava, -1, sizeof(poplava) );
   memset( slikar, -1, sizeof(slikar) );

   scanf( "%d%d", &r, &s);
   for ( int i=0; i<r; ++i )
      scanf( "%s", karta[i] );

   int slikar_r=-1, slikar_s=-1, dabar_r=-1, dabar_s=-1;

   for ( int i=0; i<r; ++i )
      for ( int j=0; j<s; ++j )
      {
         if ( karta[i][j] == 'S' )
         {
            slikar_r = i;
            slikar_s = j;
            karta[i][j] = '.';
         }
         if ( karta[i][j] == 'D' )
         {
            dabar_r = i;
            dabar_s = j;
         }
         if ( karta[i][j] == '*' ) poplava[i][j] = 0;
         if ( karta[i][j] == '.' )
         {
            bool poplavljeno = false;
            for (int k = 0; k < 4; k++)
             {
                int ni = i + potez[k][0];
                int nj = j + potez[k][1];
                if ( ni < 0 || ni >= r ) continue;
                if ( nj < 0 || nj >= s ) continue;
                if ( karta[ni][nj] == '*' ) poplavljeno = true;
             }
            if ( poplavljeno )
            {
               Q.push( make_pair(i, j) );
               poplava[i][j] = 1;
            }
         }

      }

   while ( !Q.empty() ) {
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();

      for ( int k=0; k<4; ++k )
      {
         int nx = x + potez[k][0];
         int ny = y + potez[k][1];
         if ( nx < 0 || nx >= r ) continue;
         if ( ny < 0 || ny >= s ) continue;
         if ( poplava[nx][ny] == -1 && karta[nx][ny] != 'X' && karta[nx][ny] != 'D' )
          {
            poplava[nx][ny] = poplava[x][y] + 1;
            Q.push( make_pair( nx, ny ) );
          }
      }
   }

   slikar[slikar_r][slikar_s] = 0;
   Q.push( make_pair( slikar_r, slikar_s ) );

   while ( !Q.empty() ) {
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();

      for ( int k = 0; k < 4; ++k )
       {
          int nx = x + potez[k][0];
          int ny = y + potez[k][1];
          if ( nx < 0 || nx >= r ) continue;
          if ( ny < 0 || ny >= s ) continue;
          if ( slikar[nx][ny] == -1 && karta[nx][ny] != 'X' )
            if ( poplava[nx][ny] > slikar[x][y] + 1 || poplava[nx][ny] == -1 )
             {
               slikar[nx][ny] = slikar[x][y] + 1;
               Q.push(make_pair(nx, ny));
             }
       }
   }
   if ( slikar[dabar_r][dabar_s] != -1 )
      printf( "%d\n", slikar[dabar_r][dabar_s] );
   else
      printf( "KAKTUS\n" );

   return 0;
}
