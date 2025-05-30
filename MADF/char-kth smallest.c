#include <stdio.h>
#define sch(x) scanf(" %c", &x);
#define sint(x) scanf("%d", &x);
int size;
void sw(char a[], int i, int j)
{
    char t = a[i];
    a[i] = a[j], a[j] = t;
}
void dis(char a[], int s)
{
    int i;
	for (i = 0; i < s; i++)
        printf("%c ", a[i]);
    printf("\n");
}
int part(char a[], int l, int r)
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
    dis(a, size);
    return i;
}

void ksmall(char a[], int l, int r, int x)
{

    if (r < x)
    {
        printf("out of bounds\n");
        return;
    }

    do
    {
        int p = part(a, l, r);
        printf("pivot: %d\n", p);
        if (p == x)
        {
            printf("The kth smallest element is: %c\n", a[p]);
            return;
        }
        else if (p > x)
            r = p - 1;
        else
            l = p + 1;

    } while (l <= r);

    printf("The kth smallest element is not present\n");
    return;

    // if (l <= r)
    // {
    //     int p = part(a, l, r);
    //     printf("pivot: %d\n", p);
    //     if (p == x)
    //     {
    //         printf("%dth smallest element is: %c\n", ++x, a[p]);
    //         return;
    //     }
    //     else if (p > x)
    //         ksmall(a, l, p - 1, x);
    //     else if (p < x)
    //         ksmall(a, p + 1, r, x);
    // }
    // else
    //     printf("The element is not present\n");
}

int main()
{
    // int size;
    int i;
    printf("Enter size of the array: ");
    sint(size);
    char a[size];
    for (i = 0; i < size; i++)
        sch(a[i]);
    // int a[]={42, 5, 90, 33, 28, 88, 56, 54, 11, 23, 76};
    // size=sizeof(a)/sizeof(a[0]);
    int x;
    while (x != -1)
    {
        printf("\nEnter the kth value to be searched: ");
        sint(x);
        x--;
        ksmall(a, 0, size - 1, x);
    }
    return 0;
}
