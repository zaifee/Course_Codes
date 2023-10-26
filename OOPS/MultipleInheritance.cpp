
#include <iostream>

using namespace std;

class Person{
public:
void walk(){
    cout << "Walking" << endl;
}
    
    
};






class Teacher :virtual public Person{
public:
void teaching(){
    cout << "teaching " << endl;
}
 
  
};

class Researcher : virtual public Person{
public:
void researching(){
    
    cout << "Researching" << endl;
}
    
    
    
};

class Professor : public Teacher, public Researcher{
public:
void boring(){
    cout << "Boring" << endl;
}
    
    
    
};



int main()
{
    
    Professor p;
    p.walk(); //it will not execute bcz Professor and Researcher has two walks so it will confuse 
    
    // Diamond Problem
    // 1. Solution : Scope Resolution 
    // p.Teacher::walk();
    // p.Researcher::walk();
    
    // 2. Solution
    p.walk();
  
  return 0;
}
