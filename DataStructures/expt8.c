#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
    int balance;
};
void inorder(struct node *ptr);
struct node *RotateLeft(struct node *pptr);
struct node *RotateRight(struct node *pptr);
struct node *insert(struct node *pptr, int ikey);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_LeftBalance(struct node *pptr);
struct node *insert_RightBalance(struct node *pptr);
struct node *del(struct node *pptr, int dkey);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);
struct node *del_LeftBalance(struct node *pptr, int *pshorter);
struct node *del_RightBalance(struct node *pptr, int *pshorter);

struct node *search(struct node *ptr, int skey);
struct node *min(struct node *ptr);
struct node *max(struct node *ptr);
void desc(struct node *ptr);
int getMaxWidth(struct node *root);
int getWidth(struct node* root, int level);
int height(struct node *root);

int main() {
    int choice,key;
    struct node *root=NULL,*ptr;

    while(1) {
        printf("1. Insert\n");
        printf("2. Delete an existing element\n");
        printf("3. Search an element\n");
        printf("4. List all elements in decending order\n");
        printf("5. Find maximun and minimun element of tree\n");
        printf("6. Find the width of the tree\n");
        printf("7. Exit\n\n");
        printf("Enter your choice - ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Enter the key to be inserted - ");
                scanf("%d", &key);
                root=insert(root,key);
                printf("Inorder Traversal - ");
                inorder(root);
                printf("\n\n");
                break;
            case 2:
                printf("Enter the key to be deleted - ");
                scanf("%d", &key);
                root=del(root,key);
                printf("Inorder Traversal - ");
                inorder(root);
                printf("\n\n");
                break;
            case 3:
                printf("Enter the key to be searched - ");
                scanf("%d", &key);
                ptr=search(root,key);
                if(ptr==NULL)
                    printf("Key not present\n\n");
                else
                    printf("Key present\n\n");
                break;
            case 4:
                printf("Descending order -  ");
                desc(root);
                printf("\n\n");
                break;
            case 5:
                ptr=min(root);
                if(ptr!=NULL)
                    printf("Minimun key is %d\n", ptr->info);
                ptr=max(root);
                if(ptr!=NULL)
                    printf("Maximum key is %d\n", ptr->info);
                printf("\n\n");
                break;
            case 6:
                printf("The width of the tree is - %d\n\n", getMaxWidth(root));
                break;
            case 7:
                exit(1);
            default:
                printf("re-enter choice\n");

        }
    }
    return 0;
}

struct node * insert(struct node *pptr, int ikey) {
    static int taller;
    if (pptr== NULL) {
        pptr=(struct node*)malloc(sizeof(struct node));
        pptr->info =ikey;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        pptr->balance =0;
        taller= TRUE;
    }
    else if(ikey < pptr->info) {
        pptr->lchild=insert(pptr->lchild, ikey);
        if (taller== TRUE)
            pptr=insert_left_check(pptr, &taller);
    }
    else if (ikey > pptr->info) {
        pptr->rchild=insert(pptr->rchild, ikey);
        if (taller== TRUE)

        pptr=insert_right_check(pptr, &taller);
    }
    else {
        printf("Duplicate key\n");
        taller=FALSE;
    }
    return pptr;
}

struct node * insert_left_check(struct node *pptr, int *ptaller) {
    switch( pptr->balance) {
        case 0:
            pptr->balance =1;
            break;
        case -1:
            pptr->balance=0;
            *ptaller=FALSE;
            break;
        case 1:
            pptr=insert_LeftBalance(pptr);
            *ptaller=FALSE;
    }
    return pptr;
}


struct node *insert_LeftBalance(struct node *pptr) {
    struct node *aptr , *bptr;
    aptr=pptr->lchild;
    if (aptr->balance==1) {
        pptr->balance =0;
        aptr->balance =0;
        pptr=RotateRight(pptr);
    }
    else {
        bptr=aptr->rchild;
        switch( bptr->balance) {
            case -1:
                pptr->balance =0;
                aptr->balance =1;
                break;
            case 1:
                pptr->balance =-1;
                aptr->balance =0;
                break;
            case 0:
                pptr->balance =0;
                aptr->balance =0;
        }
        bptr->balance =0;
        pptr->lchild = RotateLeft(aptr);
        pptr=RotateRight (pptr);
    }
    return pptr;
}

struct node * insert_right_check(struct node *pptr, int *ptaller) {
    switch( pptr->balance) {
        case 0:
            pptr->balance =-1;
            break;
        case 1:
            pptr->balance=0;
            *ptaller=FALSE;
            break;
        case -1:
            pptr=insert_RightBalance(pptr);
            *ptaller=FALSE;
    }
    return pptr;
}

struct node * insert_RightBalance(struct node *pptr) {
    struct node *aptr , *bptr;
    aptr=pptr->rchild;
    if (aptr->balance==-1) {
        pptr->balance =0;
        aptr->balance =0;
        pptr=RotateLeft (pptr);
    }
    else {
        bptr=aptr->lchild;
        switch( bptr->balance) {
            case -1:
                pptr->balance =1;
                aptr->balance =0;
                break;
            case 1:
                pptr->balance =0;
                aptr->balance =-1;
                break;
            case 0:
                aptr->balance =0;
            }
        bptr->balance =0;
        pptr->rchild = RotateRight(aptr);
        pptr=RotateLeft(pptr);
    }
    return pptr;
}


struct node * del(struct node *pptr, int dkey) {
    static int shorter;
    struct node *tmp,*succ;
    if (pptr== NULL) {
        printf("Duplicate key\n");
        shorter=FALSE;
        return pptr;
    }
    else if (dkey < pptr->info) {
        pptr->lchild=del(pptr->lchild, dkey);
        if (shorter == TRUE)
        pptr=del_left_check(pptr, &shorter);
    }
    else if (dkey > pptr->info) {
        pptr->rchild=del(pptr->rchild, dkey);
        if (shorter == TRUE)
        pptr=del_right_check(pptr, &shorter);
    }
    else {
        if (pptr->lchild != NULL && pptr->rchild != NULL ){
            succ = pptr->rchild ;
            while (succ->lchild !=NULL )
            succ = succ->lchild ;
            pptr->info = succ->info ;
            pptr->rchild = del(pptr->rchild ,succ->info);
            if (shorter == TRUE)
            pptr= del_right_check(pptr , &shorter);
        }
        else {
            tmp=pptr;
            if (pptr->lchild != NULL)
            pptr = pptr->lchild ;
            else if (pptr->rchild != NULL)
            pptr= pptr->rchild ;
            else
            pptr= NULL;
            free(tmp);
            shorter=TRUE;
        }
    }
    return pptr;
}

struct node * del_left_check(struct node *pptr, int *pshorter){
    switch(pptr->balance) {
        case 0:
            pptr->balance =-1;
            *pshorter=FALSE;
            break;
        case 1:
            pptr->balance=0;
            break;
        case -1:
            pptr=del_RightBalance(pptr,pshorter);
    }
    return pptr;
}

struct node *del_RightBalance(struct node *pptr, int *pshorter){
    struct node *aptr , *bptr;
    aptr=pptr->rchild;
    if (aptr->balance==0) {
        pptr->balance =-1;
        aptr->balance =1;
        *pshorter=FALSE;
        pptr=RotateLeft (pptr);
    }
    else if (aptr->balance==-1) {
        pptr->balance =0;
        aptr->balance =0;
        pptr=RotateLeft (pptr);
    }
    else {
        bptr=aptr->lchild;
        switch( bptr->balance) {
            case 0:
                pptr->balance =0;
                aptr->balance =0;
                break;
            case 1:
                pptr->balance =0;
                aptr->balance =-1;
                break;
            case -1:
                pptr->balance =1;
                aptr->balance =0;
        }
    bptr->balance =0;
    pptr->rchild = RotateRight(aptr);
    pptr=RotateLeft (pptr);
    }
    return pptr;
}

struct node * del_right_check(struct node *pptr, int *pshorter){
    switch( pptr->balance) {
        case 0:
            pptr->balance =1;
            *pshorter=FALSE;
            break;
        case -1:
            pptr->balance=0;
            break;
        case 1:
            pptr=del_LeftBalance(pptr,pshorter);
        }
    return pptr;
}

struct node * del_LeftBalance(struct node * pptr, int *pshorter) {
    struct node *aptr , *bptr;
    aptr=pptr->lchild;
    if (aptr->balance==0) {
        pptr->balance =1;
        aptr->balance =-1;
        *pshorter=FALSE;
        pptr=RotateRight(pptr);
    }
    else if (aptr->balance==1) {
        pptr->balance =0;
        aptr->balance =0;
        pptr=RotateRight (pptr);
    }
    else {
        bptr=aptr->rchild;
    
    switch( bptr->balance) {
        case 0:
            pptr->balance =0;
            aptr->balance =0;
            break;
        case 1:
            pptr->balance =-1;
            aptr->balance =0;
            break;
        case -1:
            pptr->balance =0;
            aptr->balance =1;
        }
        bptr->balance =0;
        pptr->lchild = RotateLeft (aptr);
        pptr=RotateRight(pptr);
    }
    return pptr;
}

struct node *RotateLeft(struct node *pptr) {
    struct node *aptr;
    aptr=pptr->rchild;
    pptr->rchild=aptr->lchild;
    aptr->lchild=pptr;
    return aptr;
}

struct node *RotateRight(struct node *pptr) {
    struct node *aptr;
    aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    aptr->rchild=pptr;
    return aptr;
}

struct node *min(struct node *ptr) {
    if(ptr==NULL)
        return NULL;
    else if(ptr->lchild==NULL)
        return ptr;
    else    return min(ptr->lchild);
}

struct node *max(struct node *ptr) {
    if(ptr==NULL)
        return NULL;
    else if(ptr->rchild==NULL)
        return ptr;
    else    return max(ptr->rchild);
}

struct node *search(struct node *ptr, int skey) {
    if(ptr==NULL) {
        printf("Key not found\n");
        return NULL;
    }
    else if(skey<ptr->info)
        return search(ptr->lchild, skey);
    else if(skey>ptr->info)
        return search(ptr->rchild, skey);
    else   
        return ptr;
}

void desc(struct node *ptr) {
    if(ptr==NULL) 
        return;
    desc(ptr->rchild);
    printf("%d\t", ptr->info);
    desc(ptr->lchild);
}

void inorder(struct node *ptr) {
    if(ptr==NULL) 
        return;
    inorder(ptr->lchild);
    printf("%d\t", ptr->info);
    inorder(ptr->rchild);
}

int getMaxWidth(struct node* root) {
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;
 
    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}
 
int getWidth(struct node* ptr, int level) {
 
    if (ptr == NULL)
        return 0;
 
    if (level == 1)
        return 1;
 
    else if (level > 1)
        return getWidth(ptr->lchild, level - 1) + getWidth(ptr->rchild, level - 1);
}

int height(struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    else {
        int lHeight = height(ptr->lchild);
        int rHeight = height(ptr->rchild);
 
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}
