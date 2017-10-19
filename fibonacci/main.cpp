#include <iostream>
using namespace std;

int stanje_memo[100] = { 0 };
int fib_memo( int n )
{
	if( n == 0 ) return stanje_memo[0] = 0;
	if( n == 1 ) return stanje_memo[1] = 1;

	if( stanje_memo[n] != 0 )
		return stanje_memo[n];
	else
	{
		stanje_memo[n] = fib_memo( n - 1 ) + fib_memo( n - 2 );
		return stanje_memo[n];
	}
}

int main()
{
	int N;
	cin >> N;

	cout << fib_memo( N-1 ) << endl;
	return 0;
}
