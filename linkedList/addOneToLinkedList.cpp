#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(){
    this->next = NULL;
  }
  Node(int data){
    this->data = data;
    this->next = NULL;
  
  }
};
void insertAtHead(Node* &head, Node* &tail, int data){
  if(head == NULL){

    //create a new node 
    Node* temp = new Node(data);
    head =temp;
    tail = temp;

  }
  else{
    //not empty 
    Node* newNode = new Node(data);

    // 2. pointer connect kardo temp ka already exsiting linked list se
    newNode->next = head;
//update head
       head =newNode;  //yaha galti ki thi 


  }
}
void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout << temp->data << "-";
    temp = temp->next;
  }

}

Node* reverseNode(Node* head){
  Node* prev = NULL;
  Node* curr = head;

  while(curr != NULL){
    Node* nextNodeKaPointer = curr->next;
    curr->next = prev;
    prev = curr;
   curr =nextNodeKaPointer;
  }
  return prev;
}

void addOne(Node* &head){
  //reverse
head =  reverseNode(head); //yah galti ki thi head = nhi likha tha 

  //add 1
  int carry = 1;
  Node* temp = head;
  //temp->next isliye start kar rahe rahe bcz last me head null ko point ka raha hoga 
  while(temp->next != NULL){
     int totalSum = temp->data+carry;
     int digit = totalSum%10; //bcz digit store honge only 
      carry = totalSum/10; //aage carry bhi bhejna hai 

      //jo bhi digit aaya use current node pe store karlo 
      temp->data = digit;
      temp = temp->next;

      if(carry == 0){
        break;
      }

    
  }
  if(carry != 0){
    int totalSum = temp->data + carry;
    int digit = totalSum%10;
     carry = totalSum/10;

    //digit daldo 
    temp->data = digit;
    
    if(carry != 0){
      Node* newNode = new Node(carry);
      temp->next = newNode;
    }

  }


  // reverse 
  head = reverseNode(head);

}

int main() {
  
  Node* head = NULL;
  Node* tail = NULL;
 
 insertAtHead(head, tail, 9);
 insertAtHead(head, tail, 9);
// insertAtHead(head, tail, 9);


 print(head);
 cout << endl;
 addOne(head);
 print(head);

  return 0;
}
