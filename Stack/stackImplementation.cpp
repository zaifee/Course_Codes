#include <iostream>
using namespace std;
class Stack{
public:
int *arr;
int size;
int top;

Stack(int size){
    arr = new int[size];
    this->size = size;
    this->top = -1;
}

//writing down all main functions of stack 
void push(int data){
    if(top == size-1){
        cout << "Stack Overflow" << endl;
        return;
    }
    else{
        top++;
        arr[top] = data;
        
    }
}

void pop(){
  if(top == -1){
    cout << "Stack Underflow" << endl;
    return;
  }
  top--;
}
    
bool isEmpty(){
  if(top == -1){
    return false;
  }
  else{
    cout << "Not Empty " << endl;
  }
  return true;
}

int getTop(){
  if(top = -1){
    cout << "Stack is Empty " << endl;
    return -1;
  }
  else{
    return arr[top];
  }
}

int getSize(){
  return top+1;
}

void printStack(){
  // cout << "Top " << top << endl;
  // cout << "Top Element " << getTop() << endl;
  for(int i=0; i<getSize(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
    
};

int main() {
  
  Stack st(8);

  st.push(4);
  st.push(3);
  st.push(7);
  st.push(8);
  st.pop();
  st.pop();
  //  st.pop();
  
  if(st.isEmpty()){
    cout << "Empty" << endl;
  }
  else{
    cout << "Not Empty " << endl;
  }
  
  
st.printStack();  //yaha galti ki st.print karke run hoga bcz ye class ke aandar hai

  return 0;
}
