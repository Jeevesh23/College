#include<iostream>
using namespace std;

class complex {
	int real;
	int imaginary;
	public: void input();
			void display();
			friend complex sum(complex A,complex B);
};

void complex::input() {
	cout<<"Real part = ";
	std::cin>>real;
	cout<<"Imaginary part = ";
	std::cin>>imaginary;
}

void complex::display() {
	cout<<real;
	if(imaginary>0)
	cout<<"+";
	cout<<imaginary<<"i"<<endl;
}

complex sum(complex A,complex B) {
	complex C;
	C.real=A.real+B.real;
	C.imaginary=A.imaginary+B.imaginary;
	return C;
}
int main() {
	complex a,b,c;
	cout<<"Expression 1 -"<<endl;
	a.input();
	cout<<"Expression 2 -"<<endl;
	b.input();
	c=sum(a,b);
	cout<<"Expression 1 = ";
	a.display();
	cout<<"Expression 2 = ";
	b.display();
	cout<<"Result = ";
	c.display();
}
