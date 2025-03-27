#include <stdio.h>
#include <limits.h>

#define inf INT_MAX
#define N 20

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf;
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
        printf("Enter weight: ");
        scanf("%d", &w);
        a[--x][--y] = w;
    }
}

int min_(int a, int b)
{
    return (a = a < b ? a : b);
}

int fgraph(int a[][N], int n)
{
    int dist[N]; 
    dist[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dist[i] = inf;

      
        for (int j = i; j < n; j++)
        {
            if (a[i][j] == inf)
                continue;
            else
                dist[i] = min_(dist[i], a[i][j] + dist[j]);
        }
    }
    return dist[0];
}


int main()
{
    int n, a[N][N];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    fillinf(a, n);
    printf("Enter the weights as u v w(enter -1 -1 to to stop taking input)\n");
    getmat(a, n);
    int mincost = fgraph(a, n);
    printf("The shortest path from 1 to %d using the forward approach is: %d\n", n, mincost);
    return 0;
}

/*
14
1 2 3
1 3 8
1 4 2
1 5 1
2 6 10
2 7 11
2 8 12
3 6 11
3 7 12
4 6 13
4 7 14
4 9 11
5 7 9
5 8 8
5 9 10
6 10 8
6 11 7
6 12 6
7 11 4
8 10 3
8 12 2
8 13 1
9 11 4
9 12 5
9 13 6
10 14 5
11 14 4
12 14 3
13 14 2
-1 -1
*/
