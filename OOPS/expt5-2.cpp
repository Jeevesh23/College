#include<iostream>

using namespace std;

class student {
	int roll_no;
	public: 
		void get_roll(int p) {
			roll_no=p;
			cout<<"Roll No = "<<roll_no<<endl;
		}
};

class test: public virtual student {
	protected: 
		int t1,t2;
	public: 
		void get_tmarks(int q, int r) {
			t1=q;
			t2=r;
			cout<<"Marks 1 = "<<t1<<endl<<"Marks 2 = "<<t2<<endl;
		}
};

class sports: public virtual student {
	protected: 
		int s;
	public: 
		void get_smarks(int v) {
			s=v;
			cout<<"Sports Marks = "<<s<<endl;
		}
};

class result: public test,public sports {
	private:
		int total;
	public:
		void display() {
			total=t1+t2+s;
			cout<<"Total Marks = "<<total<<endl;
		}
};

int main() {
	result r;
	r.get_roll(10);
	r.get_tmarks(100,92);
	r.get_smarks(50);
	r.display();
	return 0;
}
