#if !defined(BIRD_H)
#include <iostream>
#define BIRD_H

class Bird{
public:
 virtual void eat() = 0; //this is called pure virtual function 
 virtual void fly() = 0; 
// class that inherit this class has to implement pure virutal fun 




#endif 
};

class sparrow : public Bird{
public:
 void eat(){
   std::cout << "Sparrow is eating \n";
 }

void fly(){
  std::cout << "Sparrow is flying \n";
}

};

class eagle : public Bird{
public:
 void eat(){
   std::cout << "Eagle is eating \n";
 }

void fly(){
  std::cout << "Eagle is flying \n";
}

};

// This is the main Implementation file in which Implemented all the things 
