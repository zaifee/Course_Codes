#include <iostream>
#include<stack>
#include<queue>
using namespace std;
class Queue{
public:
int *arr;
int size;
int front;
int rear;

 Queue(int size){
  arr = new int[size];
  this->size = size;
  front = -1;
  rear = -1;
}


void push(int val){

if(rear == size){
  cout << "Overflow" << endl;
  return; //ye yaad rakhna hai 
}
else if(front == -1 && rear == -1){
  //empty wala case 
  front++;
  rear++;
  arr[rear] = val;

}else{
  arr[rear] = val;
  rear++;
}



}

void pop(){
  if(front == -1 && rear == -1){
    cout << "Queue is empty no items can be deleted " << endl;
  }
  else if(front == rear){
    //single element 
    arr[front] = -1;  //delete front se hota hai or push rear se 
    rear = -1;
    front = -1;
  }
  else{
    arr[front] = -1;
    front++; 
  }
}

bool isEmpty(){
  if(front == -1 && rear == -1){
    return true;
  }
  else{
    return false;
  }

}

bool getSize(){
  if(front == -1 && rear == -1){
    return 0;
  }
  return rear-front+1;
}

int frontElement(){
  if(front == -1){
    return -1;
  }else{
    return arr[front];
  }
}

int getRear(){
  
  return arr[rear];
}

void print(){
  cout << "Printing the Queue.. ";
  for(int i=front; i<=rear; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

};
int main() {
  
Queue q(5);
q.push(1);
q.push(10);
q.push(20);
q.push(2);
q.push(3);

q.print();
cout << "size of queue " << q.getSize() << endl;

cout << "Queue is empty or not " << q.isEmpty() << endl;
q.push(5);
q.print();
q.pop();
q.print();
q.push(4);  //it will give the overflow rear me koi space nhi hai 
cout << "size of queue " << q.getSize() << endl;
cout << "front element " << q.frontElement() << endl;

cout << "Rear element " << q.getRear() << endl;

  return 0;
}
