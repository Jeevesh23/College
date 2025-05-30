#include <stdio.h>
#include <limits.h>
#define N 10
typedef enum
{
    false,
    true
};

void fillinf(int cost[][N], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = INT_MAX;
}

void fillzeroes(int e[][N], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            e[i][j] = 0;
}

void getmat(int cost[][N], int n, int e)
{
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        if (s >= 1 && s <= n && d >= 1 && d <= n)
            cost[s][d] = w;
    }
}

void showmat(int a[][N], int n)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= n; j++)
            a[i][j] == INT_MAX ? printf("x ") : printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void shortestpath(int cost[][N], int dist[N], int n, int v)
{
    int s[N];
    for (int i = 1; i <= n; i++)
        s[i] = false, dist[i] = cost[v][i];
    s[v] = true, dist[v] = 0;
    printf("Iteration 1\n");
    for (int i = 1; i <= n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);
    printf("\n");
    for (int i = 2; i <= n - 1; i++)
    {
        int u, min = INT_MAX;
        for (int k = 1; k <= n; k++)
            if (s[k] == false && dist[k] < min)
                min = dist[k], u = k;
        printf("u: %d\n", u);
        s[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (cost[u][j] != INT_MAX && s[j] == false)
                if (dist[j] > dist[u] + cost[u][j])
                    dist[j] = dist[u] + cost[u][j];
        }
        printf("Iteration %d\n", i);
        for (int i = 1; i <= n; i++)
            printf("dist[%d] = %d\n", i, dist[i]);
        printf("\n");
    }
}

int main()
{
    int cost[N][N], dist[N], n, v, e;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    fillinf(cost, n);
    getmat(cost, n, e);
    scanf("%d", &v);

    shortestpath(cost, dist, n, v);
    printf("\n");
    printf("Starting vertex: %d\n", v);
    for (int i = 1; i <= n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);
    return 0;
}
/*
input format
8
20
1 2 15
1 3 22
1 8 11
1 6 20
2 8 5
2 3 10 
2 7 5
3 8 2
3 5 4
3 4 4
4 5 3
4 7 5
5 4 8
5 6 4
5 7 8
6 7 2
7 3 1
7 8 10
8 6 10
8 2 3
1
*/