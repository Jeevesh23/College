//File pointers
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout;
	fout.open("1.txt",ios::out);
	int p = fout.tellp();
	cout<<"\nout pointer is at : "<<p;
	
	fout.seekp(10,ios::beg);
	fout<<"Hello";
	fout.close();
	
	
	/*
	ifstream fin;
	fin.open("1.txt",ios::in);
	int q1 = fin.tellg();
	cout<<"\nIn pointer is at location : "<<q1;
	
	fin.seekg(10,ios::beg);
	int q2 = fin.tellg();
	cout<<"\nnow In pointer is at location : "<<q2<<"\n";
	
	char name1[20];
	while(fin)
	{
		fin.getline(name1,80);
		cout<<name1<<"\n";
	} */
	
	return 0;
}
