#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *prev;
	int info;
	struct node *next;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start, int data);
struct node *addatend(struct node *start, int data);
int Count(struct node *start);
void reverse(struct node *ptr);
struct node *add(struct node *num1, struct node *num2, struct node *result);

int main() {
	struct node *start1=NULL, *start2=NULL, *result=NULL;
	start1=create(start1);
	start2=create(start2);
	
    result = add(start1, start2, result);
    display(result);
    
	printf("The sum of the two numbers is: ");
    reverse(result);
    return 0;
}

struct node *create(struct node *start) {
	int n, a;
	printf("Enter the number: ");
	scanf("%d", &n);
	a=n%10;
	start=addtoempty(start,a);
	n=n/10;
	while(n>0) {
		a=n%10;
		start=addatend(start,a);
		n=n/10;
	}
	display(start);
	return start;
}

void display(struct node *start) {
	struct node *p;
	if(start==NULL) {
		printf("List is Empty\n");
		return;
	}
	p=start;
	printf("The result stored in linked list form is: ");
	while(p!=NULL) {
		printf("%d\t", p->info);
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

int Count(struct node *start) {
    int count = 0;
    struct node *ptr = start;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void reverse(struct node *ptr) {
    if (ptr == NULL) {
        printf("The list is empty lol\n");
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    while (ptr != NULL)
        printf("%d", ptr->info), ptr = ptr->prev;
    printf("\n");
}

struct node *add(struct node *num1, struct node *num2, struct node *result) {
    // findind the smaller number
    struct node *ptr1, *ptr2;
    if (Count(num1) > Count(num2))
        ptr1 = num1, ptr2 = num2;
    else if (Count(num2) > Count(num1))
        ptr1 = num2, ptr2 = num1;
    else
        ptr1 = num1, ptr2 = num2;
    int sum = 0;
    // adding zeroe
    while (Count(ptr1) != Count(ptr2))
        addatend(ptr2, 0);

    // finding sum for the first time
    sum = ptr1->info + ptr2->info;
    if (sum > 9) {
        result = addtoempty(result, sum % 10);
        sum /= 10;
        if (ptr1->next != NULL)
            ptr1->next->info += sum;
        else {
            result = addatend(result, sum);
            return;
        }
    }
    else {
        result = addtoempty(result, sum);
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    while (ptr1 != NULL) {
        sum = ptr1->info + ptr2->info;
        if (sum > 9) {
            result = addatend(result, sum % 10);
            sum /= 10;
            if (ptr1->next != NULL)
                ptr1->next->info += sum;
            else {
                result = addatend(result, sum);
                return;
            }
        }
        else {
            result = addatend(result, sum);
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return result;
}
