#include<iostream>
#include<fstream>
using namespace std;
class student
{
	char name[50];
	char address[50];
	char branch[50];
	int rollno;
	public:
		char * getname()
		{
			return name;
		}
		void getdata(void);
		void putdata(void);
};
void student::getdata(void)
{
	fflush(stdin);
	cout<<"\nEnter name : ";gets(name);
	fflush(stdin);
	cout<<"Enter roll no : ";cin>>rollno;
	fflush(stdin);
	cout<<"Enter Address : ";gets(address);
	fflush(stdin);
	cout<<"Enter branch : ";gets(branch);
}
void student::putdata(void)
{
	cout<<"NAME : "<<name<<" ";
	cout<<"ROLLNO : "<<rollno<<" ";
	cout<<"ADDRESS : "<<address<<" ";
	cout<<"BRANCH : "<<branch<<endl;
}
int main()
{
	int choice;
	student stud;
	while(1)
	{
		cout<<"\n";
		cout.fill('-');
		cout.width(35);cout<<"Menu";cout.width(30);cout<<"-";
		cout<<"\n1.Add the entry ";
		cout<<"\n2.Search ";
		cout<<"\n3.update the entry";
		cout<<"\n4.Quit";
		fflush(stdin);
		cout<<"\nchoose from menu : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"\n";cout.width(35);cout<<"ADD THE ENTRY";cout.width(30);cout<<"-";
				stud.getdata();
				ofstream file(stud.getname());
				file.write((char *)&stud, sizeof(stud));
				break;
			}
			case 2:
			{
				cout<<"\n";cout.width(35);cout<<"SEARCH";cout.width(30);cout<<"-";
				char n[30];
				cout<<"\nEnter name to search : ";
				fflush(stdin);
				gets(n);
				ifstream file(n);
				if(file.good())
				{
					file.read((char *)&stud,sizeof(stud));
					stud.putdata();
				}
				else
					cout<<"\n"<<n<<" student is not there in record";
					break;
			}
			case 3:
			{
				fflush(stdin);
				cout<<"\n";cout.width(35);cout<<"UPDATE";cout.width(30);cout<<"-";
 				cout<<"\nEnter name of student to be updated : ";
 				char n[50];
 				fflush(stdin);
 				gets(n);
 				ofstream file(n,ios::trunc);
 				if(file.good())
 				{
 					cout<<"Enter new data";
 					stud.getdata();
 					file.write((char *)&stud,sizeof(stud))<<flush;
 					rename(n,stud.getname());
				}
				else
 					cout<<"\n"<<n<<" student is not there in record";
					break;
			}
		case 4:
		{
			exit(1);
		}
		default:
		{
			cout<<"\ninvalid choice ";
			break;
		}
 	}
}
return 0;
}

