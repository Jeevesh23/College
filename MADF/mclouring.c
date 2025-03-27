#include <stdio.h>

int count = 0;
int G[20][20];

void fill_zeros(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = 0;
        }
    }
}

void get_edges(int edges) {
    int origin,dest;
    printf("Enter the u and v edge:\n ");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &origin, &dest);
        G[origin][dest] = 1;
        G[dest][origin] = 1;
    }
}

void Print(int x[], int n) {
    printf("Solution %2d -  ", ++count);
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void NextValue(int x[], int n, int m, int k) {
    do 
    {
        x[k] = (x[k] + 1) % (m + 1); // next highest color
        if (x[k] == 0)               // all colors have been used
            return;
        int j;
        for (j = 1; j <= n; j++) {
            /* checking if this color is distinct from adjacent colors
            if (k,j) is an edge and if adjacent vertex have same color */
            if (G[k][j] != 0 && (x[k] == x[j]))
                break;
        }
        if (j == n + 1) // new colour found
            return;
    } while (1);
}

void mColoring(int x[], int n, int m, int k) {
    do
    {
        // generate all legal assignments for x[k]
        NextValue(x, n, m, k);
        if (x[k] == 0) // no new colour possible
            return;
        if (k == n) // atmost m colours has been used to colour n vertices
            Print(x, n);
        else
            mColoring(x, n, m, k + 1);
    } while (1);
}


int main()
{
    int n, m;
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    fill_zeros(n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges: \n");
    get_edges(edges);
    

    printf("\nEnter number of colors: ");
    scanf("%d", &m);
    int x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    printf("\nThe Solutions are: \n");
    mColoring(x, n, m, 1);

    return 0;
}