#include <stdio.h>
#define N 20
int board[N];

int place(int row, int col)
{
    for (int i = 1; i <= row - 1; i++)
    {
        if (board[i] == col)
            return 0;
        else if (abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void show(int n)
{
    printf("\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf("\tQ"); // indicates that a queen has been placed
            else
                printf("\t_"); // queen not placed
        }
    };
    printf("\n\n");
}

void nqueen(int row, int n)
{
    for (int col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                show(n);
                return;
            }
            else
                nqueen(row + 1, n);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueen(1, n);
    return 0;
}
