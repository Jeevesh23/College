#include<iostream>
using namespace std;

class students //single base class
{
    protected: int roll_no;
	public:
 		void get_roll(int a) {
			roll_no=a;
		}
		void display() {
			cout<<"Roll No = "<<roll_no<<endl;
		}
};
class arts : public students //arts is derived from class base
{
    protected: int h_marks;
	public:
 	void history_marks(int b) {
 	    h_marks=b;
		cout<<"History Marks = "<<h_marks<<endl;
 	}
};
class engineering : public students //engineering is also derived from class base
{	
	protected: int m_marks;
    public:
 	void maths_marks(int b) {
 	    m_marks=b;
		cout<<"Maths Marks = "<<m_marks<<endl;
 	}
};
class medical : public students //medical is also derived from class base
{
    protected: int a_marks;
	public:
 	void anatomy_marks(int c) {
 	    a_marks=c;
		cout<<"Anatomy Marks = "<<a_marks<<endl;
 	}
};
class mech : public engineering //mech is derived from class base engineering
{	
	protected: int t_marks;
    public:
		void thermodynamics_marks(int d) {
 	    	t_marks=d;
			cout<<"Thermodynamics Marks = "<<t_marks<<endl;
 	}
};
class elec : public engineering //elec is also derived from class base engineering
{
    protected: int e_marks;
	public:
		void circuit_marks(int e) {
 	    e_marks=e;
		cout<<"Circuit Marks = "<<e_marks<<endl;
 	}
};
class civil : public engineering //civil is also derived from class base engineering
{
    protected: int c_marks;
	public:
		void construction_marks(int f) {
 	    c_marks=f;
		cout<<"Construction Marks = "<<c_marks<<endl;
 	}
};
	
int main()
{
	arts s1;
	medical s2;
	mech s3;
	elec s4;
	civil s5;

	s1.get_roll(21);
	s2.get_roll(22);
	s3.get_roll(23);
	s4.get_roll(24);
	s5.get_roll(25);

	s1.history_marks(78);
	s2.anatomy_marks(98);
	s3.maths_marks(85);
	s4.maths_marks(92);
	s5.maths_marks(72);
	s3.thermodynamics_marks(66);
	s4.circuit_marks(58);
	s5.construction_marks(99);
    
    return 0;
}
