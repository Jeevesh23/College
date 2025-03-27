#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout1,fout2;
	fout1.open("country.txt");
	fout1<<"US"<<"\n";
	fout1<<"United kingdom"<<"\n";
	fout1.close();
	
	fout2.open("capital.txt");
	fout2<<"washington"<<"\n";
	fout2<<"london"<<"\n";
	fout2.close();
	
	/*
	char name1[80],name2[80];
	ifstream fin1,fin2;
	fin1.open("country.txt");
	while(fin1)
	{
		fin1.getline(name1,80);
		cout<<name1<<"\n";
	}
	fin1.close();
	
	fin2.open("capital.txt");
	while(fin2)
	{
		fin2.getline(name2,80);
		cout<<name2<<"\n";
	}
	fin2.close();
	*/
	
	/*
	char line1[80],line2[80];
	
	ifstream fin1,fin2;
	fin1.open("country.txt");
	fin2.open("capital.txt");
	
	for(int i=1;i<=2;i++)
	{
		fin1.getline(line1,80);
		cout<<"Capital of "<<line1<<" is ";
		fin2.getline(line2,80);
		cout<<line2<<"\n";
	}
	
	fin1.close();
	fin2.close();
	
	*/
	return 0;
}
