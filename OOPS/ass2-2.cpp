#include<iostream>

using namespace std;

class electricity {
    char name[30];
    float unit;
    float price;
    
	public: void calculate(electricity *);
            void enter_details(electricity *);
            void display(electricity *);
};

void electricity :: enter_details(electricity *a) {
    cout<<"\nEnter Consumer's name: ";
    cin>>a->name;
    cout<<"Enter units of electricity used: ";
    cin>>a->unit;
    getchar();
}

void electricity :: calculate(electricity *a) {
    int extra;

    if(a->unit<=100) {
        a->price=(60*a->unit)/100 + 50;
    } 
    else if (a->unit>100 && unit<=300) {
        extra=a->unit-100;
        a->price=(60*100)/100 + (80*extra)/100 + 50;
    }
    else if (a->unit>300) {
        extra=unit-300;
        a->price=(60*100)/100 + (80*200)/100 + (90*extra)/100 + 50;
        if(a->price>300) {
            a->price=a->price + 0.15*price;
        }  
    }
}

void electricity :: display(electricity *a) {
	cout << "\nDetails are:\n";
    cout << "Name: " << a->name << endl;
    cout << "Charges: " << a->price << " Rupees" << endl;
}

int main() {
    
    electricity a[100];
    int choice, i=0, j;
    
    while(choice!=3) {
        cout<<"\n1. Enter Details"<<endl;
        cout<<"2. Display all details"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;
        switch(choice) {
            case 1: {
            	cout<<"Enter details"<<endl;
                a[i].enter_details(&a[i]);
                a[i].calculate(&a[i]);
                i++;
                break;
            }
            case 2: {
            	for(j=0; j<i; j++) {
            		a[j].display(&a[j]);
				}
				break;
			}
            case 3: {
                exit(1);
            }
            default: {
                cout<<"Re-enter choice"<<endl;
            }
        }
    }
    return 0;
}
