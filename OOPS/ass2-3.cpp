#include<iostream>

using namespace std;

class DB;

class DM {
	 float mt,cm;
	 public:
			 void getdata() {
			  cout<<"Enter the distance in meter: ";
			  cin>>mt;
			  cout<<"Enter the distance in centimeter: ";
			  cin>>cm;
			 }
			 void display() {
			  cout<<"\nThe distance is:";
			  cout<<mt<<" meters and "<<cm<<" centimeter";
			 }
			 friend void add(DM &,DB &);
};

class DB {
	 float inch,feet;
	 public:
			 void getdata() {
			  cout<<"Enter the distance in feet: ";
			  cin>>feet;
			  cout<<"Enter the distance in inches: ";
			  cin>>inch;
			 }
			 void display() {
			  cout<<"\nThe distance is:";
			  cout<<feet<<" feet and "<<inch<<" inch";
			 }
			 friend void add(DM &,DB &);
};

void add(DM &a,DB &b) {
	DM x;
	int c=(a.mt*100+a.cm+b.feet*30.48+b.inch*2.54);
	if(c>=100) {
		x.mt=c/100;
		x.cm=c%100;
	} else {
	   	x.mt=0;
	   	x.cm=c;
	}
	x.display();
	
	DB y;
	int i=(a.mt*39.37+a.cm*.3937008+b.feet*12+b.inch);
	if(i>=12) {
	   	y.feet=i/12;
	   	y.inch=i%12;
	} else {
	   	y.feet=0;
	   	y.inch=i;
	}
	y.display();
}

int main() {
	DM a;
	DB b;
	a.getdata();
	b.getdata();
	add(a,b);
}
