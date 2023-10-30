

#include <iostream>

using namespace std;
class A{
private:
int x;
public:
int y;

//ctor 
A(int _val):x(_val){};

//getter and setter 
int getX() const {return x;}
void setx(int _value){x = _value;}

    friend class B;  //this is how we declare the friend class 
    friend void print(const A &); //this is how we declre the friend function 
    
    
};

class B{
public:
//we have a requirement that we have to use every data member of class A 
void print(const A&srcObj){  //Here we take class A and making a obj of class a //yaha galti hogi const se to get x ko bhi const declare karna padega
    cout << srcObj.getX() << endl;
    cout << srcObj.x << endl; //this is a private member of class a so it will not run 
                              //but it will run if we declare the friend of class a 
}
    
    
    
};

// a fun that access that access the private member of class a 
void print(const A&a){
    cout << a.x << endl;
}

int main()
{
    A a(5);
    B b;
    b.print(a); //passing a in in class b object 
    print(a);
    
    return 0;
}
