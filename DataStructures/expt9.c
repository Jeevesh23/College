#include<stdio.h>
#include<stdlib.h>
typedef enum {false,true} boolean;
struct node {
    struct node *left;
    boolean lthread;
    int info;
    boolean rthread;
    struct node *right;
};
struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert(struct node *root, int ikey);
struct node *del(struct node *root, int dkey);
struct node *case_a(struct node *root, struct node *par, struct node *ptr);
struct node *case_b(struct node *root, struct node *par, struct node *ptr);
struct node *case_c(struct node *root, struct node *par, struct node *ptr);
void inorder(struct node *root);
struct node *search(struct node *ptr, int skey);


int main() {
    int choice, num;
    struct node *root=NULL, *ptr;
    while(1) {
        printf("1. Insert an key\n");
        printf("2. Delete a key\n");
        printf("3. Search a key\n");
        printf("4. Perform a inorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice - ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("Enter the key to be inserted - ");
                scanf("%d", &num);
                root=insert(root,num);
                printf("\n");
                break;
            case 2:
                printf("Enter the key to be deleted - ");
                scanf("%d", &num);
                root=del(root,num);
                printf("\n");
                break;
            case 3:
                printf("Enter the key to be searched - ");
                scanf("%d", &num);
                ptr=search(root,num);
                if(ptr==NULL)
                    printf("Key not present\n\n");
                else
                    printf("Key present\n\n");
                break;
            case 4:
            printf("Inorder Traversal -  ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

struct node *insert(struct node *root, int ikey) {
    struct node *tmp, *par, *ptr;
    int found=0;
    ptr=root;     par=NULL;
    while(ptr!=NULL) {
        if(ikey==ptr->info) {
            found=1;
            break;
        }
        par=ptr;
        if(ikey<ptr->info) {
            if(ptr->lthread==false)
                ptr=ptr->left;
            else
                break;
        }
        else {
            if(ptr->rthread==false)
                ptr=ptr->right;
            else   
                break;
        }
    }
    if(found)
        printf("Duplicate key\n");
    else {
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lthread=true;
        tmp->rthread=true;
        if(par==NULL) {
            root=tmp;
            tmp->left=NULL;
            tmp->right=NULL;
        }
        else if(ikey<par->info) {
            tmp->left=par->left;
            tmp->right=par;
            par->lthread=false;
            par->left=tmp;
        }
        else {
            tmp->left=par;
            tmp->right=par->right;
            par->rthread=false;
            par->right=tmp;
        }
    }
    return root;
}

struct node *del(struct node *root, int dkey) {
    struct node *par, *ptr;
    int found=0;
    ptr=root;   par=NULL;
    while(ptr!=NULL) {
        if(dkey==ptr->info) {
            found=1;
            break;
        }
        par=ptr;
        if(dkey<ptr->info) {
            if(ptr->lthread==false)
                ptr=ptr->left;
            else    break;
        }
        else {
            if(ptr->rthread==false)
                ptr=ptr->right;
            else
                break;
        }
     }
     if(found==0)
        printf("dkey is not present in tree\n");
    else if(ptr->lthread==false && ptr->rthread==false)
        root=case_c(root,par,ptr);
    else if(ptr->lthread==false)
        root=case_b(root,par,ptr);
    else if(ptr->rthread==false)
        root=case_b(root,par,ptr);
    else    
        root=case_a(root,par,ptr);
    return root;
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr) {
    if(par==NULL)
        root=NULL;
    else if(ptr==par->left) {
        par->lthread=true;
        par->left=ptr->left;
    }
    else {
        par->rthread=true;
        par->right=par->right;
    }
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr) {
    struct node *child, *s, *p;

    if(ptr->lthread==false)
        child=ptr->left;
    else    
        child=ptr->right;
    if(par==NULL)
        root=child;
    else if(ptr==par->left)
        par->left=child;
    else 
        par->right=child;
    s=in_succ(ptr);
    p=in_pred(ptr);
    if(ptr->lthread==false)
        p->right=s;
    else {
        if(ptr->rthread==false)
            s->left=p;
    }
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr) {
    struct node *succ, *parsucc;

    parsucc=ptr;
    succ=ptr->right;
    while(succ->left!=NULL) {
        parsucc=succ;
        succ=succ->left;
    }
    ptr->info=succ->info;
    if(succ->lthread==true && succ->rthread == true)
        root=case_a(root, parsucc, succ);
    else    
        root=case_b(root,parsucc, succ);
    return root;
}

struct node *search(struct node *ptr, int skey) {
    if(ptr==NULL) {
        printf("Key not found\n");
        return NULL;
    }
    else if(skey<ptr->info)
        return search(ptr->left, skey);
    else if(skey>ptr->info)
        return search(ptr->right, skey);
    else   
        return ptr;
}

void inorder(struct node *root) {
    struct node *ptr;
    if(root==NULL) {
        printf("Tree is empty\n");
        return;
    }
    ptr=root;

    while(ptr->lthread==false)
        ptr=ptr->left;
    while(ptr!=NULL) {
        printf("%d\t", ptr->info);
        ptr=in_succ(ptr);
    }
}

struct node *in_succ(struct node *ptr) {
    if(ptr->rthread==true)
        return ptr->right;
    else {
        ptr=ptr->right;
        while(ptr->lthread==false)
            ptr=ptr->left;
        return ptr;
    }
}

struct node *in_pred(struct node *ptr) {
    if(ptr->lthread==true)
        return ptr->left;
    else {
        ptr=ptr->left;
        while(ptr->rthread==false)
            ptr=ptr->right;
        return ptr;
    }
}

