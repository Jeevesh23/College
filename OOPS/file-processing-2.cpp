#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout;
	fout.open("hello");
	fout<<"morning";
	fout.open("hello",ios::app|ios::trunc);
	int p = fout.tellp();
	cout<<"\nPut ptr : "<<p;
	
	return 0;
}
