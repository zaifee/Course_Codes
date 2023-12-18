#include <iostream>
using namespace std;
class Dequeue{
public:
int *arr;
int size;
int front;
int rear;

Dequeue(int size){
  arr = new int[size];
  this->size = size;
  front = -1;
  rear = -1;
}

void pushFront(int val){
  if(front == 0 && rear == size-1 || (rear = front-1)){
    cout << "Overflow " << endl;
  }

  else if(front == -1 &&  rear == -1){
    front++; rear++;
    arr[front] = val;
  }
  else if(front != 0 && rear != size-1){
      front = size-1;
      arr[front] = val;
  }
  else{
    front--; //front ko ghata rhe 
    arr[front] = val;
  }



}

void pushBack(int val){
//overflow 
  if((front == 0 && rear == size-1 || (rear = front-1)){
    cout << "Overflow " << endl;
  }
  
  else if(front == -1 && rear == -1){
    front++; rear++;
    arr[rear] = val;
  }
    
  else if(rear == size-1 && front != 0){
    rear = 0;
    arr[rear] = val;
  }
     
  else{
    rear++;
    arr[rear] = val;
    
  }



}

void popFront(){
  //underflow
if(front == -1 && rear == -1){
  cout << "Underflow" << endl;
}
else if(front == size-1){
    // Circular wala case
      arr[front] = -1;
      front++;
  }
else if(front == rear){
  //single element 
  arr[front] = -1;
  front = -1;
  rear = -1;
}
else{
  //normal case
  arr[front] = -1;
  front++;
}

}

void popBack(){
if(front == -1 && rear == -1){
  cout << "Underflow" << endl;
}
else if(front == rear){
  //single element 
  arr[rear] = -1;
  front = -1;
  rear = -1;
}
else if(rear == 0){
  arr[rear] = -1;
  rear = size-1;
}
else{
  //normal case 
  arr[rear] = -1;
  rear--;
}

}



};
int main() {
  
  
  return 0;
}
