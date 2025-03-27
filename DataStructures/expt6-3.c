#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;
};
struct node *create_list(struct node *last);
void display(struct node *start);
struct node *addtoempty(struct node *last, int data);
struct node *addatend(struct node *last, int data);
int Count(struct node *last);
struct node *deletenode(struct node *last);

int main() {
	struct node *last=NULL;
	last=create_list(last);
	printf("The List before deletion: ");
	display(last);
	last = deletenode(last);
    printf("The list after deletion: ");
    display(last);
	return 0;
}

struct  node *create_list(struct node *last) {
	int i, n, data;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	last=NULL;
	if(n==0) {
		return last;
	}
	printf("Enter the element to be inserted: ");
	scanf("%d", &data);
	last=addtoempty(last,data);
	for(i=2;i<=n;i++) {
		printf("Enter the element to be inserted: ");
		scanf("%d", &data);
		last=addatend(last,data);
	}
	return last;
}

void display(struct node *last) {
	struct node *p;
	if(last==NULL) {
		printf("List is emepty\n");
		return;
	}
	p=last->link;
	do {
		printf("%d\t", p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}

struct node *addtoempty(struct node *last, int data) {
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}

struct node *addatend(struct node *last, int data) {
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}

int Count(struct node *last) {
    struct node *p = last->link;
    if (last == NULL)
        return 0;
    int count = 0;
    do {
        count++, p = p->link;
    } while (p != last->link);
    return count;
}

struct node *deletenode(struct node *last) {
    struct node *ptr=last, *first=last->link;
    while(ptr->link->link!=first) {
        struct node *tmp=ptr->link->link;
        ptr->link->link=tmp->link;
        free(tmp);
        ptr=ptr->link;
        if(ptr->link==first) {
            last=ptr;
            return last;
        }
    }
	return last;
}
