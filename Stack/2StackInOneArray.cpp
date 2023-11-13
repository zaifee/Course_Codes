#include <iostream>
using namespace std;

class Stack{

public:
int* arr;
int data;
int size;
int top1;
int top2;

Stack(int size){
  arr = new int[size];
  this->size = size;
  top1 = -1;
  top2 = size;
}

void push1(int data){
  
  if(top2 - top1 == 1){
    cout << "Overflow Stack" << endl; //stack full hai
  }else{
     top1++;
     arr[top1] = data;
  }
 
  
}
void push2(int data){
 
  if(top2 - top1 == 1){
    cout << "Overflow stack" << endl; //stack full hai 
  }else{

   top2--;
   arr[top2] = data;
  }
}

void pop1(){
 //underflow means full condition stack full to nhi hai 
  if(top1 == -1){
    cout << "Data cannot be inserted " << endl;
  }else{
    arr[top1] = 0;
  top1--;
  }

  

}

void pop2(){
    if(top1 == -1){
    cout << "Data cannot be inserted " << endl;
  } 
  else{
    
  arr[top2] = 0;
  top2++;
  }

}

void printStack(){
  cout << "Top1 " << top1 << endl;
  cout << "Top2 " << top2 << endl;
  for(int i=0; i<size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
} 


};


int main() {
  
  Stack s(6);
  s.printStack();
  s.push1(2);
  s.printStack();
  s.push1(3);
  s.printStack();
  s.push2(100);
  s.printStack();
  s.push2(200);
   s.printStack();
   s.push2(300);
   s.printStack();
   s.push1(4);
   s.printStack();

   //now stack1 and stack2 both are full 
    s.push1(5);
   s.printStack();

// Deleting from stack1
   s.pop1();
   s.printStack();
 
 // Deleting from stack2
   s.pop2();
   s.printStack();




  return 0;
}
