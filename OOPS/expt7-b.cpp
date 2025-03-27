#include <iostream>
#include <string>	
#include<iomanip>

using namespace std;

int main(){
	string str;	 
	int words = 0, ch = 0, lines = 0;
   	
	cout << "Enter a string\n";
	do {
        getline(cin, str);
        lines++;	
        ch += str.length();
        for (int i = 0; i <= str.length(); ++i)	{					//accessing the string character by character
			if (str[i] == ' ' || str[i] == '\0')						//counting the umber of words
					++words;
	}
    } while(str.length());
    
	words=words-1;
    lines=lines-1;

	cout << setw(30) << setiosflags(ios::left) << "Number of words";  
	cout << setw(30) << setiosflags(ios::left) << "Number of characters";
	cout << setw(30) << resetiosflags(ios::right) << "Number of lines"<<endl;
	resetiosflags(ios::left);
	cout << setiosflags(ios::right) << setw(15) << words;
	cout  << setiosflags(ios::right) << setw(35) << ch;
	cout <<setw(25) << lines << endl;


	return 0;
}
