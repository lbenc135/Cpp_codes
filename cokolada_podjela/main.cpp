#include <iostream>
using namespace std;

#define MAX 100

int tablica[MAX+1][MAX+1] = { 0 };

int podjela_cokolade( int a, int b )
{
	if( a == b ) return 0;
	if( tablica[a][b] != 0 )
		return tablica[a][b];

	int rj = 100000000;
	for( int i = 1; i < a; ++i )	//Pokusavamo rezati vodoravno
		rj = min( rj, podjela_cokolade( i, b ) + podjela_cokolade( a-i, b ) + 1 );

	for( int i = 1; i < b; ++i )	//Pokusavamo rezati okomito
		rj = min( rj, podjela_cokolade( a, i ) + podjela_cokolade( a, b-i ) + 1 );

	tablica[a][b] = rj;
	return rj;
}

int main()
{
	int N, M;
	cin >> N >> M;

	cout << podjela_cokolade( N, M );
	return 0;
}
