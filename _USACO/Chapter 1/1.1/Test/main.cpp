/*
ID: lbenc131
PROG: test
LANG: C++
*/
#include <cstdio>

using namespace std;

int main() {
    FILE *fin  = fopen ("test.in", "r");
    FILE *fout = fopen ("test.out", "w");
    int a, b;
    fscanf(fin, "%i %i", &a, &b);
    fprintf(fout, "%i\n", a+b);
    return 0;
}
