#include<iostream>

using namespace std;

class Base {
    public:
        void display() { cout << "\n Display Base ";}
        virtual void show() { cout << "\n Show Base ";}
};
class Derived : public Base {
    public:
        void display() { cout << "\n Display Derived";}
        void show() { cout << "\n Show Derived \n";}
};

int main() {
    Base B;
    Derived D;
    Base *bptr;

    cout<<"\n bptr points to Base\n";
    bptr=&B;
    bptr->display();   // calls Base version
    bptr->show();      // calls Base version

    cout<<"\n\n bptr points to derived\n";
    bptr=&D;
    bptr->display();     // calls Base version
    bptr->show();        // calls Derived version

    return 0;
}