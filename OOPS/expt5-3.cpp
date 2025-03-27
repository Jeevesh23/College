#include<iostream>

using namespace std;

class alpha {
	int x;
	public:
		alpha(int i) {
			x=i;
			cout<<"Alpha Initialised "<<endl;
		}
		void show_x() {
			cout<<x<<endl;
		}		
};

class beta {
	float y;
	public:
		beta(float j) {
			y=j;
			cout<<"Beta initialised "<<endl;
		}
		void show_y() {
			cout<<y<<endl;
		}
};

class gamma: public beta, public alpha {
	int m,n;
	public:
		gamma(int a, float b, int c, int d): alpha(a),beta(b) {
			m=c;
			n=d;
			cout<<"Gamma initialised"<<endl;
		}
		void show_mn() {
			cout<<m<<" and "<<n<<endl;
		}
};

int main() {
	gamma g(5,10.5,20,30);
	g.show_x();
	g.show_y();
	g.show_mn();
	return 0;
}
