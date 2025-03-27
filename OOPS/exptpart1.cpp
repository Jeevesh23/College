#include<iostream>
#include<string.h>

using namespace std;

	class book {
      char name[30];
                char author[30];
                int pages;

       public : void enter_book(book*b);
                void display_book(book*b );
                void search_author(book*b,int );
                void search_title(book*b,int);
    };
    
    void book::enter_book(book *b) {
        getchar();
        cout << "\nEnter name: ";
        cin >> b->name;
        getchar();
        cout << "Enter author: ";
        cin >> b->author;
        getchar();
        cout << "Enter number of Pages: ";
        cin>> b->pages;
    }

    void book::display_book(book *b) {
        cout << "\nTitle: " << b->name ;
        cout << "\nAuthor: " << b->author ;
        cout << "\nPages: " << b->pages ;
    }
    
    void book::search_title(book*b,int n) {
    	int j;
		cout << "Enter title: ";
	    char title[30];
	    getchar();
	    cin >> title;
	    for(j=0;j<n;j++){
	        if(strcmp(b[j].name, title)==0){
	            b[j].display_book(&b[j]);
	            break;
	        } else {
	        	cout<< "Book not found\n";
			}
	    }
	}
	
	void book::search_author(book*b,int n) {
		int j;
		cout<< "Enter author: ";
	    char author[30];
	    getchar();
	    cin >> author;
	    for(j=0;j<n;j++){
	        if(strcmp(b[j].author, author)==0){
	            b[j].display_book(&b[j]);
	            break;
	        } else {
	        	cout<< "Book not found\n";
			}
	    }
	}

    int main() {

        int n=0, i=0, j=0, choice;
		book b[100];

        while(1) {
        	cout<< "\n\nChoose an option\n";
        	cout<<"1)Insert a book record\n";
	       	cout<<"2) Search based on title\n";
	        cout<<"3) search based on author\n";
	        cout<<"4) display all book records\n";
	        cout<<"5) Exit\n";

	        cin >> choice;

	        switch (choice) {
	            case 1: {
                    cout<<"Insert Book record:\n";
	            	b[n].enter_book(&b[n]);
        			n++;
	                break;
	            }

	            case 2: {
	                b[i].search_title(&b[i],n);
	                break;
	            }

	            case 3: {
	                b[i].search_author(&b[i],n);
	                break;
	            }

	            case 4: {
	                for(int j=0;j<n;j++){
	                    b[j].display_book(&b[j]);
	                }
	                break;
	            }

	            case 5: {
					exit(1);
				}
                default: {
					cout<<"Entered wrong choice\n";
					break;
				}
	        }
		}
		return 0;
    }







