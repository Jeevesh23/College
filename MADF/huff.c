#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sint(x) scanf("%d", &x)
#define N 100

struct node
{
    int freq;
    char c;
    struct node *next, *left, *right;
};

struct node *start = NULL;

greatest = 0; // this holds the greatest freq

void addatend(char c[], int f[], int n)
{
    for (int i = 0; i < n; i++)
    {

        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->c = c[i], start->freq = f[i], start->next = NULL, start->left = NULL, start->right = NULL;
        }
        else
        {
            struct node *ptr = start;

            while (ptr->next != NULL)
                ptr = ptr->next;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->c = c[i], temp->freq = f[i];
            temp->next = temp->left = temp->right = NULL, ptr->next = temp;
        }
    }
}
void showlist()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("(%c, %d), ", ptr->c, ptr->freq);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *delfront()
{
    struct node *temp = start;
    start = start->next;
    return temp;
}

void addafterliketerms(struct node *temp)
{
    // check if there is only one
    if (start == NULL)
        start = temp;
    else if (start->next == NULL) // only one term
    {
        if (temp->freq < start->freq)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            temp->next = start->next;
            start->next = temp;
        }
    }
    else
    {
        int found = 0;
        struct node *at, *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->freq == temp->freq)
            {
                found = 1, at = ptr;
                break;
            }
            ptr = ptr->next;
        }
        ptr = start;
        if (found)
        {
            struct node *ptr = at;
            while (ptr->next->freq == temp->freq && ptr->next != NULL)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
        else
        {
            ptr = start;
            while (ptr->next->freq <= temp->freq && ptr != NULL)
                ptr = ptr->next;
            if (ptr != NULL)
            {
                temp->next = ptr->next;
                ptr->next = temp;
            }
            else
            {
                ptr = start;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }
}

void ins_end(struct node *temp)
{
    if (start == NULL)
        temp->next = NULL, start = temp;
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void huffman()
{
    if (!start)
        return;

    while (start->next != NULL)
    {
        struct node *a = delfront(), *b = delfront(), *temp = (struct node *)malloc(sizeof(struct node));
        temp->c = '#', temp->freq = a->freq + b->freq, temp->left = a, temp->right = b, temp->next = NULL;
        if (temp->freq >= greatest)
            greatest = temp->freq, ins_end(temp);
        else
            addafterliketerms(temp);
        showlist();
        printf("\n");
    }
}

void printcodes(struct node *root, int path[], int stringlen)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        for (int i = 0; i < stringlen; i++)
            printf("%d", path[i]);
        printf("\t%c\n", root->c);
    }

    // left tree
    path[stringlen] = 0;
    printcodes(root->left, path, stringlen + 1);

    // right tree
    path[stringlen] = 1;
    printcodes(root->right, path, stringlen + 1);
}

void findgreatest()
{
    struct node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    greatest = ptr->freq;
}

int main()
{
    // char arr[] = {'j', 'f', 'a', 'r', 'g', 'g', 'm', 's', 'h', 'p', 'o','n', 'e', 'i', 't', 'sp'};
    // int freq[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 4, 4, 5, 6, 6, 7};
    // j is the position of the partitioning element
    char arr[17] = {'j', 'f', 'a', 'r', 'g', 'l', 'm', 's', 'h', 'p', 'o','n', 'e', 'i', 't', ' '};
    int freq[17] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 4, 4, 5, 6, 6, 7};
    printf("%d\n", strlen(arr));
    addatend(arr, freq, strlen(arr));
    showlist();
    findgreatest();
    huffman();
    int path[N];
    printf("Huffman Codes\n");
    printcodes(start, path, 0);

    return 0;
}