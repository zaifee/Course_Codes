#include <iostream>

using namespace std;

class queue{
public:
int *arr;
int size;
int front;
int rear;

queue(int size){
  arr = new int(size);
  this->size = size;
  front = -1;
  rear = -1;
}

void push(int val){
  //check full
  if(rear == size-1){
    cout << "Overflow" << endl;
    return;
  }
  else if(front == rear == -1){
    //not full
    //empty case
    front++; rear++;
    arr[rear] = val;
  }else{
    //normal case 
    rear++;
    arr[rear] = val;
  }
  
}


void pop(){
  if(front == rear == -1){
    cout << "Underflow ! cannot delete the element " << endl;
  }
  else if(front == rear){
    //single element wala case
    arr[rear] = -1;
    front = -1;
    rear = -1;
  }
  else{
    //normal case 
    arr[front] = -1;
    front++;
  }
}



};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
