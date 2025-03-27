#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	int info;
	struct node *next;
};
struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start, int data);
struct node *addatend(struct node *start, int data);
void swap(struct node **start);

int main() {
	struct node *start=NULL;
	start=create_list(start);
	printf("List before swapping: ");
	display(start);
	swap(&start);
	printf("List after swapping: ");
	display(start);
	return 0;
}

struct node *create_list(struct node *start) {
	int i,n,data;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	start=NULL;
	if(n==0) {
		return start;
	}
	printf("Enter the element to be inserted: ");
	scanf("%d", &data);
	start=addtoempty(start,data);
	for(i=2;i<=n;i++) {
		printf("Enter the element to be inserted: ");
		scanf("%d", &data);
		start=addatend(start,data);
	}
	return start;
}

void display(struct node *start) {
	struct node *p;
	if(start==NULL) {
		printf("List is Empty\n");
		return;
	}
	p=start;
	printf("Elements in the list is: ");
	while(p!=NULL) {
		printf("%3d", p->info);
		p=p->next;
	}
	printf("\n\n");
}

struct node *addtoempty(struct node *start, int data) {
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=NULL;
	start=temp;
	return start;
}

struct node *addatend(struct node *start, int data) {
	struct node *temp, *p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
	temp->next=NULL;
	temp->prev=p;
	return start;
}

void swap(struct node **start) {
    struct node *p = *start, *temp;
    if (p->next == NULL)
        return;
    temp = p->next;
    temp->prev = NULL;
    p->prev = temp;
    p->next = temp->next;
    temp->next = p;
    *start = temp;
    p->next->prev = p;
    p = p->next;

    while (p != NULL) {
        temp = p->next;
        temp->prev = p->prev;
        p->prev = temp;
        p->next = temp->next;
        temp->next = p;
        if (p->next != NULL)
            p->next->prev = p;
        temp->prev->next = temp;
        p = p->next;
    }
}
