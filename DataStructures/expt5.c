#include<stdio.h>
#include<Stdlib.h>

struct node {
	int info;
	struct node *link;
};

void convert(int, int);
void tofh(int ndisk, char source, char tmp, char dest);
int GCD(int, int);
void reverse(char *ch);
struct node *create_list(struct node*start);
int search(struct node *start, int data);
struct node *addatbeg(struct node*start, int data);
struct node *addatend(struct node*start, int data);

int main() {
	int choice;
	struct node *start;
	int item;
	start = create_list(start);
	while(choice!=6) {
		printf("\n1. Base conversion\n");
		printf("2. Tower Hanoi\n");
		printf("3. Greatest Common Divisor\n");
		printf("4. Reverse a string\n");
		printf("5. Search an item in a linked list\n");
		printf("6. Exit \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: {
				int num;
				printf("Enter a positive decimal number: ");
				scanf("%d", &num);
				printf("Binary form: ");
				convert(num, 2);
				printf("\nOctal form: ");
				convert(num, 8);
				printf("\nHexadecimal form: ");
				convert(num, 16);
				printf("\n");
				break;
			}
			case 2: {
				char source = 'A', tmp = 'B', dest = 'C';
				int ndisk;
				printf("Enter the number of disks: ");
				scanf("%d", &ndisk);
				printf("Sequence is :\n");
				tofh(ndisk,source,tmp,dest);
				printf("\n");
				break;
			}
			case 3: {
				int a,b;
				printf("Enter number 1: ");
				scanf("%d", &a);
				printf("Enter number 2: ");
				scanf("%d", &b);
				printf("GCD of %d and %d is %d", a,b,GCD(a,b));
				printf("\n");
				break;
			}
			case 4: {
				char ch[30];
				int i;
				printf("Enter the string: ");
				getchar();
				gets(ch);
				printf("Reversed string is: ");
				reverse(ch);
				printf("\n");
				break;
			}
			case 5: {
				printf("Enter element to be searched: ");
				scanf("%d", &item);
				search(start,item);
				break;
			}
			case 6: {
				exit(1);
			}
			default: 
				printf("Entered wrong choice. Please re-enter\n");
		}
		
	}
	return 0;
}

void convert(int num, int base) {
	int rem = num%base;
	if(num==0)
		return;
	convert(num/base, base);
	
	if(rem<10)
		printf("%d",rem);
	else 
		printf("%c", rem-10+'A');;
}

void tofh(int ndisk, char source, char tmp, char dest) {
	if(ndisk==1) {
		printf("Move Disk %d from %c --> %c\n", ndisk,source,dest);
		return;
	}
	tofh(ndisk-1,source,dest,tmp);
	printf("Move Disk %d from %c --> %c\n", ndisk,source,dest);
	tofh(ndisk-1,tmp,source,dest);
}

int GCD(int a, int b) {
	if(b==0)
		return a;
	return GCD(b, a%b);
}

void reverse(char *ch) {
	if(*ch=='\0')
		return;
	reverse(ch+1);
	printf("%c", *ch);
}

struct node * create_list(struct node * start){
	int i,n,data;
	printf("Enter the number of nodes : " );
	scanf("%d",&n );
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg(start,data );
	for(i=2;i<=n;i++) {
		printf("Enter the element to be inserted : " );
		scanf("%d",&data);
		start=addatend(start,data );
	}
	return start;
}

int search(struct node *start, int item) {
	struct node *ptr;
	ptr=start;
	if(ptr==NULL) {
		printf("Element not found\n");
		return;
	}
	if(ptr->info==item) {
		printf("Element found\n");
		return;
	}
	return search(ptr->link,item);
}
		
struct node *addatbeg(struct node *start, int data) {
	struct node *tmp;
	tmp= (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}
	
struct node *addatend(struct node *start, int data) {
	struct node *tmp, *p;
	tmp= (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while(p->link!=NULL) {
		p = p->link;
	}
	p->link=tmp;
	tmp->link = NULL;
	return start;
}
