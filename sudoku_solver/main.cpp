#include <cstdio>
#include <cstdlib>
using namespace std;

const bool DEBUG=0;

int sudoku[9][9];

void ispis()
{
    system("cls");
    for(int i=0;i<9;i++)
    {
        if(i%3==0) printf("-------------------------\n");
        for(int j=0;j<9;j++)
        {
            if(j%3==0) printf("| ");
            printf("%i ", sudoku[i][j]);
            if(j==8) printf("| ");
        }
        if(i==8) printf("\n-------------------------");
        printf("\n");
    }
}

bool is_in_row(int val, int row)
{
    for(int i=0;i<9;i++)
        if(sudoku[row][i]==val) return true;
    return false;
}

bool is_in_col(int val, int col)
{
    for(int i=0;i<9;i++)
        if(sudoku[i][col]==val) return true;
    return false;
}

bool is_in_box(int val, int x, int y)
{
    x*=x/3;
    y*=y/3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(sudoku[i+x][j+y]==val) return true;
    return false;
}

bool solve()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(!sudoku[i][j])
            {
                for(int k=1;k<=9;k++)
                {
                    if(!is_in_row(k, i) && !is_in_col(k, j) && !is_in_box(k, i, j))
                    {
                        sudoku[i][j]=k;

                        if(DEBUG) ispis();

                        if(solve()) return true;
                        else sudoku[i][j]=0;
                    }
                }
                if(sudoku[i][j]==0) return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            scanf("%i", &n);
            sudoku[i][j]=n;
        }
    if(solve()) ispis();
    else printf("Impossible to solve!\n");
}

/*
3 0 6 5 0 8 0 0 0
5 0 0 0 3 0 0 0 0
0 0 9 0 0 0 0 3 1
0 7 0 0 1 0 0 8 0
9 0 0 0 6 0 0 0 5
0 5 0 0 9 0 6 0 0
1 0 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
4 9 0 0 0 0 1 0 0
*/
