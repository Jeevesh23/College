#include <stdio.h>
#include <limits.h>
#define N 30
#define inf 99999

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf;
}

void fillz(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 0;
}

void getmat(int a[][N], int n)
{
    int w, x, y;
    for (int i = 0; i < n * (n - 1); i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if (x == -1 && y == -1)
            return;
        scanf("%d", &w);
        a[--x][--y] = w;
    }
}

int _min(int a, int b)
{
    return a < b ? a : b;
}

void allpair(int cost[][N], int A[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = cost[i][j];
    fillz(A, n);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
    }
}

void display(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == inf)
                printf("inf ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int cost[N][N], A[N][N], n;
    printf("Enter the number of vertices - ");
    scanf("%d", &n);
    fillinf(cost, n);
    printf("Enter the weights as u v w(enter -1 -1 to to stop taking input)\n");
    getmat(cost, n);
    allpair(cost, A, n);
    printf("The shortest path matrix is\n");
    display(A, n);
    return 0;
}

/*
4
1 2 5
1 4 1
2 1 4
2 3 8
2 4 3
3 2 7
3 4 5
4 1 2
4 2 4
4 3 2
-1 -1
*/

