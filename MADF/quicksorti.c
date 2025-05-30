#include <stdio.h>

// utility functions for qs
int size, count = 1;

void sw(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j], a[j] = t;
}

void dis(int a[], int s)
{	
	int i;
    for (i = 0; i < s; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int part(int a[], int l, int r)
{
    int j;
	int piv = a[r], i = l; // we choose the rightmost element is the pivot
    for (j = l; j < r; j++)
    {
        if (a[j] < piv)
        {
            sw(a, i, j);
            i++;
        }
    }
    sw(a, i, r);
    return i;
}

void qs(int a[], int l, int r)
{
    // step 1: find the partition index
    if (l < r)
    {
        int p = part(a, l, r);
        printf("pass %d: ", count), count++;
        dis(a, size);
        qs(a, l, p - 1);
        qs(a, p + 1, r);
    }
}

int main()
{
	int i;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int a[size];
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("Original Array: ");
    dis(a, size);
    qs(a, 0, size - 1);
    printf("Sorted Array: ");
    dis(a, size);
    return 0;
}
