	#include<stdio.h>
	#include<string.h>
	#include<math.h>
	#include<stdlib.h>
	#define BLANK ' '
	#define TAB '\t'
	#define MAX 50
	
	void push(long int symbol);
	long int pop();
	void infix_to_postfix();
	void infix_to_prefix();
	long int eval_post();
	long int eval_pre();
	int priority(char symbol);
	int isEmpty();
	int white_space(char symbol);
	char infix[MAX], postfix[MAX], prefix[MAX];
	long int stack[MAX];
	int top;
	
	main() {
	
		long int value1,value2;
		int choice;
		top=-1;
		printf("Enter infix : ");
		gets(infix);
		
		while(choice!=5) {
			printf("1. Infix to Postfix\n");
			printf("2. Infix to Prefix\n");
			printf("3. Evaluate infix to postfix\n");
			printf("4. Evaluate infix to prefix\n");
			printf("5. Exit\n");
			printf("Enter choice: ");
			scanf("%d", &choice);
			
			switch(choice) {
				case 1: {
					infix_to_postfix();
					printf("Postfix: %s\n",postfix);
					value1=eval_post();
					break;
				}
				case 2: {
					infix_to_prefix();
					printf("Prefix %s\n", prefix);
					value2=eval_pre();
					break;
				}
				case 3: {
					printf("Value of expression : %ld\n", value1);
					break;
				}
				case 4: {
					printf("Value of expression : %ld\n",value2);
					break;
				}
				case 5: {
					exit(1);
				}
				default: {
					printf("Entered wrong choice\n");
					break;
				}
			}
		}
		
		
		
	}
	
	void push(long int symbol) {
		if(top>MAX) {
			printf("Stack Overflow\n");
			exit(1);
		}
		stack[++top]=symbol;
	}
	
	long int pop() {
		if(isEmpty()) {
			printf("Stack Underflow\n");
			exit(1);
		}
		return (stack[top--]);
	}
	
	int isEmpty() {
		if(top==-1) 
			return 1;
		else 
			return 0;
	}
	
	void infix_to_postfix() {
		unsigned int i, p=0;
		char next;
		char symbol;
		for(i=0; i<strlen(infix); i++) {
			symbol=infix[i];
			if(!white_space(symbol)) {
				switch(symbol) {
					case '(':
					push(symbol);
					break;
					case ')':
						while((next=pop())!='(') 
							postfix[p++] =next;
						break ;
					case '+':
					case '-':
					case '*':
					case '/':
					case '%':
					case '^':
					
					while(!isEmpty() && priority(stack[top]) >= priority(symbol) )
						postfix[p++]=pop();
					push(symbol) ;
					break ;
					
					default:
						postfix[p++]=symbol;
					}
				}
			}
			while(!isEmpty())
				postfix[p++]=pop();
			postfix[p]='\0';	
	}
	
	long int eval_post() {
		long int a,b,temp,result;
		unsigned int i;
		for(i=0;i<strlen(postfix);i++) {
			if(postfix[i]<='9' && postfix[i]>='0') {
				push(postfix[i]-'0');
			} else {
				a=pop();
				b=pop();
				switch(postfix[i]) {
					case '+':
						temp=b+a; break;
					
					case '-':
						temp=b-a; break;
					
					case '*':
						temp=b*a; break;
					
					case '/':
						temp=b/a; break;
					
					case '%':
						temp=b%a; break;
					
					case '^':
						temp=pow(b,a);
				}
			    push(temp);
			
			}
		
		}
		result=pop();
		return result;
		
	}
	
	int priority(char symbol) {
		switch(symbol) {
			case '(': 
				return 0;
			
			case '+':
			case '-':
				return 1;
			
			case '*':
			case '/':
			case '%':
				return 2;
			
			case '^':
				return 3;
			default: 
				return 0;
		}
	}

	int white_space(char symbol) {
		if(symbol==BLANK || symbol==TAB)
			return 1;
		else
			return 0;
	}
	
	
	
	void infix_to_prefix() {
		int i, j, p=0;
		char next;
		char symbol;
		char temp;
		for(i=strlen(infix)-1; i>=0; i--) {
			symbol=infix[i];
			if(!white_space(symbol)) {
				switch(symbol) {
					case ')':
						push(symbol);
						break;
					case '(':
						while((next=pop())!=')') 
							prefix[p++] =next;
						break ;
					case '+':
					case '-':
					case '*':
					case '/':
					case '%':
					case '^':
					
					while(!isEmpty() && priority(stack[top]) >= priority(symbol) )
						prefix[p++]=pop();
					push(symbol) ;
					break ;
					
					default:
						prefix[p++]=symbol;
					}
				}
			}
			while(!isEmpty())
				prefix[p++]=pop();
			prefix[p]='\0';	
			for(i=0, j=p-1;i<j;i++,j--) {
				temp=prefix[i];
				prefix[i]=prefix[j];
				prefix[j]=temp;
			}
	}
	
	long int eval_pre() {
		long int a,b,temp,result;
		int i;
		for(i=strlen(prefix)-1;i>=0;i--) {
			if(prefix[i]<='9' && prefix[i]>='0') {
				push(prefix[i]-48);
			} else {
				a=pop();
				b=pop();
				switch(prefix[i]) {
					case '+':
						temp=a+b; break;
					
					case '-':
						temp=a-b; break;
					
					case '*':
						temp=a*b; break;
					
					case '/':
						temp=a/b; break;
					
					case '%':
						temp=a%b; break;
					
					case '^':
						temp=pow(a,b);
				}
			    push(temp);
			
			}
		
		}
		result=pop();
		return result;
		
	}
