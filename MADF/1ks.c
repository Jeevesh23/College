#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 200
#define obj 100
int count = 0; // this is used to print the subsets

int size;

struct dp
{
    int p, w, o[obj];
    // here p = profit, w = weight and o array holds zeroes and ones, indicating whether the eobject has been included in the knapsack or not
};

void get(int a[N], int n)
{
    for (int i = 0; i < n; i++)
        sint(a[i]);
}

void purrrrrge(struct dp s[N])
// (=｀ω´=)...
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (s[i].p < s[j].p && s[i].w >= s[j].w)
                s[i].p = s[i].w = -1;
            else if (s[j].p < s[i].p && s[j].w >= s[i].w)
                s[j].p = s[j].w = -1;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (s[i].p == s[j].p && s[i].w == s[j].w)
                s[j].p = s[j].w = -1;
        }
    }
}

void knap(int m, int n, int p[N], int w[N])
{
    struct dp s[N];
    s[0].w = s[0].p = 0; // this represents an empty knapsack ie. no profit, no weight
    for (int i = 0; i < n; i++)
        s[0].o[i] = 0;

    size = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = size; j < size; j++, k++)
        // j represents the index of the entry in the prev row that is being copied
        // k represents the idex of the new entry that is beign created
        {
            // check if the entry in the prev row is valid
            if (s[j].w == -1)
                continue;

            s[k].w = s[j].w + w[i];

            // check if the weight exceeds the knapsack cap
            if (s[k].w > m)
            {
                s[k].w = s[k].p = -1;
                continue;
            }

            // if it does not exceed, we proceed to update the profits
            s[k].p = s[j].p + p[i];

            for (int z = 0; z < n; z++)
                s[k].o[z] = s[j].o[z];
            s[k].o[i] += 1;
        }
        purrrrrge(s);
        printf("S^%d = { ", count);
        for (int i = 0; i < size; i++)
        {
            if (s[i].p == -1 && s[i].w == -1)
                continue;
            else
                printf("(%d, %d) ", s[i].p, s[i].w);
        }
        printf("}");
        printf("\n");
        size *= 2, count++;
    }
    purrrrrge(s);
    int mw = -1, mp = -1, ind; // mp = max profit, mw = max weight, ind = index
    for (int i = 0; i < size; i++)
    {
        if (s[i].w < mw)
            continue;
        else if (s[i].w > mw)
            mw = s[i].w, mp = s[i].p, ind = i;
        else
        {
            if (s[i].p > mp)
                mp = s[i].p, ind = i;
        }
    }
    printf("Max Profit: %d\nKnapsack filled at: %d\nObjects: ( ", mp, mw);
    for (int i = 0; i < n; i++)
    {
        if (s[ind].o[i] != 1)
            printf("0 ");
        else
            printf("%d ", s[ind].o[i]);
    }
    printf(")\n");
}

int main(int argc, char const *argv[])
{
    int m, n; // m = max knapsack size, n = number of items
    printf("Enter the knapsack capacity: ");
    sint(m);
    printf("Enter the number of elements: ");
    sint(n);
    int p[n], w[n]; // p is the array holding the profits and w the weights
    printf("Enter the profit for each item\n");
    get(p, n);
    printf("Enter the weights for each item\n");
    get(w, n);
    knap(m, n, p, w);
    return 0;
} 


/*
7
15
18 4 6 21 7 14 13
3 1 3 4 1 1 2
*/