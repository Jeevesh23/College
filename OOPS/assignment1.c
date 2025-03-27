#include <stdio.h>
#include<string.h>
    typedef struct {
        char name[30];
        char author[30];
        int pages;
    }book;

    void display_book(book *b){
        printf("Title: %s\n", b->name);
        printf("Author: %s\n", b->author);
        printf("Pages: %d\n\n", b->pages);
        return;
    }

    void enter_book(book *b){
        getchar();
        printf("Enter name: ");
        gets(b->name);
        printf("Enter author: ");
        gets(b->author);
        printf("Enter number of Pages: ");
        scanf("%d", &b->pages);
        return;
    }

    int main() {
        printf("How many books: ");
        int n, i, j, choice;
        scanf("%d", &n);
        getchar();
        book b[n];
        for( i=0;i<n;i++){
            enter_book(&b[i]);
        }
        
		while(1) {
        	printf("Choose an option\n");
	        printf("1) Insert a book record\n");
	        printf("2) Search based on title\n");
	        printf("3) search based on author\n");
	        printf("4) delete a book record\n");
	        printf("5) display all book records\n");
	        printf("6) Exit\n");
			scanf("%d", &choice);
        
        	switch (choice) {
        	case 1: {
        		enter_book(&b[n]);
        		n++;
				break;
			}
			case 2: {
                printf("Enter title: ");
                char title[30];
                getchar();
                gets(title);
                for(i=0;i<n;i++){
                    if(strcmp(b[i].name, title)==0){
                        display_book(&b[i]);
                    }
                }
                break;
            }
			case 3: {
                printf("Enter author: ");
                char author[30];
                getchar();
                gets(author);
                for(i=0;i<n;i++){
                    if(strcmp(b[i].author, author)==0){
                        display_book(&b[i]);
                    }
                }
                break;
        	}	
			case 4: {
                printf("Enter name of the book to be deleted: ");
                char title[30];
                getchar();
                gets(title);
                for(i=0;i<n;i++){
                    if(strcmp(title, b[i].name)==0){
                        for(j=i;j<n;j++){
                            b[j] = b[j+1];
                        }
                    }
                }
                n--;
                break;
            }	
            case 5: {
                for(i=0;i<n;i++){
                    display_book(&b[i]);
                }
                break;
            }

            case 6: {
                exit(1);
            }
        }	
		}
        return 0;
    }

