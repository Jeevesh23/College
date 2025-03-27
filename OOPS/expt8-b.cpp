#include<iostream>

using namespace std;

template<class T>
class vector {
    T *v;
    int size;
    public:
        vector(int m) { // parameterized constructor to create NULL vector
            size=m;
            v=new T[size];
            for(int i=0;i<size;i++)
                v[i]=0;
        }

        void create() {
            for(int i=0;i<size;i++) {
                cout<<"v["<<i<<"] = ";
                cin>>v[i];
            }
        }

        void modify()   {
            int pos;
            cout<<"enter position to make changes :";
            cin>>pos;
            cout<<"Enter new Value :";
            cin>>v[pos-1];
        }

        void display() {
            int i;
            cout<<"(";
            for(i=0;i<size-1;i++) {
                cout<<v[i]<<",";
            }
            cout<<v[i]<<")\n";
        }
};

int main() {
    int size;
    cout<<"enter size of vector: ";
    cin>>size;
    cout<<"Enter the vector\n";
    vector<int> v1(size); //creates int vector
    v1.create();
    v1.display();
    v1.modify();
    v1.display();
    cout<<"-----------------------\n";
    cout<<"Enter the vector\n";
    vector<float> v2(size); //creates float vector
    v2.create();
    v2.display();
    cout<<"-----------------------\n";
    cout<<"Enter the vector\n";
    vector<char> v3(size); //creates char vector
    v3.create();
    v3.display();
    return 0;
}
