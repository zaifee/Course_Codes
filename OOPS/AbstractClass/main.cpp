#include<iostream>
#include "bird.h" 
using namespace std;

void birddoesSomething(Bird *&bird){
  bird->eat();
  bird->fly();
  bird->eat();  //In this we did not explictly write the name of class like sparrow->eat , pigeon->eat, sparrow->fly , all these are done through abstraction 
  bird->eat();
  bird->fly();
  bird->eat(); 
  bird->eat();
  bird->fly();
  bird->eat();
}

int main(){

  Bird *bird = new sparrow(); //Hfer one line of code changes everything 
  birddoesSomething(bird);

  Bird *b2 = new Bird(); //we cannot do it bcz it is interface 

  


  
  return 0;
}
