#include <iostream>
using namespace std;
  
// Function template to swap two elements
template <class T>
void swap_numbers(T& x, T& y) {
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}
  
int main() {
    int a, b;
    a = 10, b = 20;
    cout<<"a and b before swap - "<<"a = "<<a<<" b = "<<b<<endl;
    swap_numbers(a, b);                 //int swap
    cout<<"a and b after swap - "<<"a = "<<a<<" b = "<<b<<"\n\n";

    float c, d;
    c = 10.34, d = 20.54;
    cout<<"c and d before swap - "<<"a = "<<c<<" b = "<<d<<endl;
    swap_numbers(c, d);                 //float swap
    cout<<"c and d after swap - "<<"a = "<<c<<" b = "<<d<<"\n\n";

    char e, f;
    e = 'x', f = 'y';
    cout<<"e and f before swap - "<<"a = "<<e<<" b = "<<f<<endl;
    swap_numbers(e, f);                 // char swap
    cout<<"e and f after swap - "<<"a = "<<e<<" b = "<<f<<endl;
    return 0;
}




