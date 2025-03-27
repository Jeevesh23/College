/*#include<iostream>
using namespace std;
  
class media {
   int x;
   public:
    virtual void information() = 0;
    int getX() { return x; }
};
  
// This class inherits from Base and implements fun()
class book: public media {
    int y;
public:
    void fun() { cout << "Function fun() called"; }
};

class tape: public media {
    int y;
public:
    void fun() { cout << "Function fun() called"; }
};
  
int main(void)
{
    Derived d;
    d.fun();
    return 0;
}






#include <iostream>  
using namespace std;  
// Abstract class  
class Shape  
{  
    public:  
    virtual float calculateArea() = 0; // pure virtual function.  
};  
class Square : public Shape  
{  
    float a;  
    public:  
    Square(float l)  
    {  
        a = l;  
    }  
    float calculateArea()  
    {  
        return a*a;  
    }  
};  
class Circle : public Shape  
{  
    float r;  
    public:  
      
    Circle(float x)  
    {  
        r = x;  
    }  
    float calculateArea()  
    {  
        return 3.14*r*r ;  
    }  
};  
class Rectangle : public Shape  
{  
    float l;  
    float b;  
    public:  
    Rectangle(float x, float y)  
    {  
       l=x;  
       b=y;  
    }  
    float calculateArea()  
    {  
        return l*b;  
    }  
};  
int main()  
{  
      
    Shape *shape;  
    Square s(3.4);  
    Rectangle r(5,6);  
    Circle c(7.8);  
    shape =&s;  
    int a1 =shape->calculateArea();  
    shape = &r;  
    int a2 = shape->calculateArea();  
    shape = &c;  
    int a3 = shape->calculateArea();  
    std::cout << "Area of the square is " <<a1<< std::endl;  
    std::cout << "Area of the rectangle is " <<a2<< std::endl;  
    std::cout << "Area of the circle is " <<a3<< std::endl;  
    return 0;  
}  

*/

#include<iostream>
using namespace std;
class Media {
	int x;
	public:
		void getmedia(int a) {
			x=a;
		}
		virtual void display()=0;
};
class Book:public Media {
	protected:
		int y;
	public:
		void getbook(int b) {
			y=b;
		}
		void display() {
			cout<<"Total books - "<<y<<endl;
		}
	
};
class Tape:public Media {
	protected:
		int z;
	public:
		void gettape(int b) {
			z=b;
		}
		void display() {
			cout<<"Total tapes - "<<z<<endl;
		}
	
};

int main() {
	Book b;
	Tape t;
	b.getbook(10);
	t.gettape(20);
	b.display();
	t.display();
	return 0;
}

