//Read & write function in file processing
#include<iostream>
#include<fstream>
using namespace std;
class inventory
{
	char name[10];
	int code;
	public:
		void readdata();
		void writedata();
};
void inventory::readdata()
{
	cout<<"\nEnter item name : \n";cin>>name;
	cout<<"\nEnter item code : \n";cin>>code;
}
void inventory::writedata()
{
	cout<<"\nitem name is : "<<name;
	cout<<"\nitem code is : "<<code;
}
int main()
{
	inventory item[2],item2[2];
	
	ofstream file1;
	
	file1.open("inventory.txt",ios::out);
	
	cout<<"\nEnter the item details into the file : \n";
	for(int i=1;i<=2;i++)
	{
		item[i].readdata();
		file1.write((char *) & item[i], sizeof(item[i]));
	}
	file1.close();
	
		
	ifstream file2;
	file2.open("inventory.txt",ios::in);
	
	cout<<"\nItem details read from the file are as follows : ";
	for(int i=1;i<=2;i++)
	{
		file2.read((char *) & item2[i], sizeof(item2[i]));
		item2[i].writedata();
	}
	
	file2.close();
	
	return 0;
}
