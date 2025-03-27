#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char info[100];
    struct node *link;
} *top = NULL;

int isEmpty() {
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(char *item) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory cannot be allocated\n");
        exit(1);
    }
    strcpy(temp->info, item);
    temp->link = top;
    top=temp;
}

int stack_count() {
    struct node *p;
    int count;
    p = top;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}

char *pop() {
    struct node *temp;
    char *s = malloc(100);
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return;
    }
    temp = top;
    top = top->link;
    strcpy(s, temp->info);
    free(temp);
    return s;
}

void conv_postfix_to_infix() {
    char postfix[200], infix[400], symbol[2], symb, a[200], b[200], tempstr[400] = "";
    printf("\nEnter the postfix array: ");
    scanf("%s", postfix);
    int i;
    for ( i = 0; postfix[i] != '\0'; i++) {
        char symbol[2] = {postfix[i], '\0'};
        symb = postfix[i];
        switch (symb){
	        case '+':
	        case '-':
	        case '*':
	        case '/':
	        case '%':
	        case '^':
	            if (stack_count() < 2) {
	                printf("There are no sufficient terms in the expression\n");
	                exit(1);
	            }
	            strcpy(a, pop());
	            strcpy(b, pop());
	            sprintf(tempstr, "%s %s %s %s %s", "(", b, symbol, a, ")");
	            push(tempstr);
	            break;
	        default:
	            push(symbol);
        }
    }
    if (stack_count() == 1)
        printf("Infix Expression : %s\n", pop());
    else
        printf("Unable to convert\n");
    top = NULL;
    printf("\n");
}

int main() {
	
	conv_postfix_to_infix();
	return 0;
}
