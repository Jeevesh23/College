#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int n,m;
	ofstream of1("file1.txt");
	cout<<"Enter the number elements in file 1 - ";
	cin>>m;
	cout<<"\nEnter 3 elements\n";
	for(int i=1;i<=m;i++)
	{
		cin>>n;
		of1<<n<<"\n";
	}
	of1.close();
	
	cout<<"\n Elements from file are as follows\n";
	ifstream if1("file1.txt");
	for(int i=1;i<=m;i++)
	{
		if1>>n;
		cout<<n<<"\n";
	}
	if1.close();
	
	int x,y;
	ofstream of2("file2.txt");
	cout<<"Enter the number of elements in file 2 - ";
	cin>>x;
	cout<<"\nEnter elements\n";
	for(int i=1;i<=x;i++)
	{
		cin>>y;
		of2<<y<<"\n";
	}
	of2.close();
	
	int a,b;
	
	cout<<"\n elements from file are as follows\n";
	ifstream if2("file2.txt");
	for(int i=1;i<=x;i++)
	{
		if2>>a;
		cout<<a<<"\n";
	}
	if2.close();
	
	ofstream of3;
	while(if1.eof()==0)
     {
          if1>>b;
          of3<<b;
     }
     while(if2.eof()==0)
     {
          if2>>y;
          of3<<y;
     }
	
	if1.close();
    if2.close();
    of3.close();
    
    cout<<"\n elements from file are as follows\n";
	ifstream if3("file3.txt");
	while(if3.eof()==0) {
		if2>>y;
		cout<<y<<"\n";
	}
	
	
	return 0;
}
