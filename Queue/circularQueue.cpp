#include <iostream>

using namespace std;
class CQueue{
public:
int *arr;
int size;
int front;
int rear;

CQueue(int size){
  arr = new int[size];
  this->size = size;
  front= -1;
  rear = -1;
}

void push(int val){
  //overflow 
  if((front == 0 && rear == size-1)  || rear == front-1){  //
    cout << "Queue Overflow " << endl;
  }
  else if(front == -1 && rear == -1){
    //empty wala case 
    front++;
    rear++;
    arr[rear] = val;

  }
  else if(rear == size-1 && front != 0){
    //circular wala case 
    
      rear = 0;
      arr[rear] = val;
  }
  else{
    //normal case 
    rear++;
    arr[rear] = val;
  }
    
  
}

void pop(){
  //Underflow wala case 
  if(front == -1 && rear == -1 ){
    cout << "Queue Underflow " << endl;
  }
  else if(front == rear){
    // single elment in queue
      arr[front] = -1;
      front = -1;
      rear = -1;
     
  }
  else if(front == size-1){
    // Circular wala case
      arr[front] = -1;
      front++;
  }
  else{
    //normal case
    arr[front] = -1;
    front++;
  }

}


void print(){
  cout << "Printing the Queue element " << endl;
  for(int i=0; i<size; i++){
    cout << arr[i] << " ";

  }
  cout << endl;
}

};
int main() {
  CQueue cq(5);
  cq.push(3);
  cq.print();

  cq.push(4);
  cq.print();

  cq.push(5);
  cq.print();

  cq.push(6);
  cq.print();

  cq.push(7);
  cq.print();
  
  
  cq.pop();
  cq.pop();
  cq.pop();
  cq.print();

  cq.push(100);
  cq.print();

  cq.push(110);
  cq.print();

  cq.push(120);
  cq.print();

  cq.push(130);  //130 push nhi hona chaiye tha overflow aana chaiye tha we replaced 6 with 130 
  cq.print();
  return 0;
}
