/*
ID: lbenc131
PROG: milk3
LANG: C++
*/
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int bc[3];
set<int> s;

int sit[21][21][21];

void DFS(int a, int b, int c)
{
    sit[a][b][c]=1;
    if(a==0) s.insert(c);

    int col;
    // iz A -> B
    col=min(a, bc[1]-b);
    if(!sit[a-col][b+col][c]) DFS(a-col, b+col, c);
    // iz A -> C
    col=min(a, bc[2]-c);
    if(!sit[a-col][b][c+col]) DFS(a-col, b, c+col);
    // iz B -> A
    col=min(b, bc[0]-a);
    if(!sit[a+col][b-col][c]) DFS(a+col, b-col, c);
    // iz B -> C
    col=min(b, bc[2]-c);
    if(!sit[a][b-col][c+col]) DFS(a, b-col, c+col);
    // iz C -> A
    col=min(c, bc[0]-a);
    if(!sit[a+col][b][c-col]) DFS(a+col, b, c-col);
    // iz C -> B
    col=min(c, bc[1]-b);
    if(!sit[a][b+col][c-col]) DFS(a, b+col, c-col);
}

int main() {
    FILE *fin  = fopen ("milk3.in", "r");
    FILE *fout = fopen ("milk3.out", "w");

	fscanf(fin, "%i %i %i", &bc[0], &bc[1], &bc[2]);

    DFS(0, 0, bc[2]);

    for(set<int>::iterator i=s.begin();i!=s.end();i++)
    {
        fprintf(fout, "%i", *i);
        if(i!=--(s.end())) fprintf(fout, " ");
        else fprintf(fout, "\n");
    }

    return 0;
}
