//Static Data Member;

#include <iostream>

using namespace std;
class student{
public:
static int x, y;

void printNumber() const{
    cout << x << " " << y << endl;
}
   
};

//It is way to tell there will be one instane of class member with static data member 
int student :: x;  //student class sab instances ek hi x ko share karenge 
int student :: y; //student class sab instances ek hi y ko share karenge


int main()
{
    student a;
    a.x = 1;
    a.y = 2;
    a.printNumber();
    
    student obj2;
    obj2.x = 10;
    obj2.y = 0;
    obj2.printNumber();
    a.printNumber(); //yaha a ko obj2 ke x and y ki value hi assign kar di gyi 

    return 0;
}


// Static Data Member function 


// Stati Member fun 

#include <iostream>

using namespace std;
class student{
public:
// static int x, y; 
//if we simple x and y  
int x, y;

student(int x, int y):x(0),y(0){};

// WE cannot use static member function without static keyword  
static void printNumber(){
    //error they dont ye kiska x and y hai excute hi nhi honge;
    //if only access static variable inside the static function 
    // cout << x << " " << y << endl;  
    printf("I'am in Static data Member function %s", _FUNCTION_);
}
    
    
    
    
    
    
};

//It is way to tell there will be one instane of class member with static data member 
// int student :: x;
// int student :: y;

int main()
{
    student a;
    // student::x = 1;
    // student::y = 2;
    student::printNumber();
    
    student obj2;
    // student::x = 10;
    // student::y = 0;
    student::printNumber();
    student::printNumber(); //yaha a ko obj2 ke x and y ki value hi assign kar di gyi 

    return 0;
}

