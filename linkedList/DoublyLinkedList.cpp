#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;

Node(){
  this->prev = NULL;
  this->next = NULL;
}

Node(int data){
  this->data = data;
  this->prev = NULL;
  this->next = NULL;
}

};
void print(Node* head){
  Node* temp = head;

  while(temp  != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int findLength(Node* head){
   Node* temp = head;
  int len = 0;
  while(temp  != NULL){
        len++;
    temp = temp->next;
  }
  return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
   if(head == NULL){
     Node* newNode = new Node(data);

     head = newNode;
     tail = newNode;
   }


   else{
// Inc case of Non empty linked list

  //create a node 
  Node* temp = new Node(data);
   
   temp->next = head;
   head->prev = temp;
     head =  temp;
   }
}

void insertAtTail(Node* &head, Node* &tail, int data){
 if(tail == NULL){
   Node* temp = new Node(data);
     head = temp;
     tail = temp;
 }
else{
  //linked list empty nhi hai
  Node* newNode = new Node(data);
 
  tail->next = newNode;
  newNode->prev = tail;
  tail =newNode;

}
}

void insertAtAnyPos(Node* &head, Node* &tail, int data, int pos){
  int len = findLength(head);
  if(head == NULL){
    //empty ll 
    Node* temp = new Node(data);
      head = temp;
      tail = temp;
  }
  else if(pos == len){
     insertAtTail(head, tail, data);
  }
  else if(pos == 1){
    insertAtHead(head, tail, data);
  }
  else{
// insert at middle 
   Node* newNode = new Node(data);
  //traverse the node 
  Node* prevNode = NULL;
  Node* currNode = head;
   while(pos != 1){
         prevNode= currNode;
         currNode = currNode->next;
         pos--;
   }
   prevNode->next = newNode;
   newNode->prev = prevNode;
   newNode->next = currNode;
   currNode->prev = newNode;
  }

}

void  deleteFromHead(Node* &head, Node* &tail){
    if(head == NULL){
      cout << "Node cannot be deleted " << endl;
    }
    else{
       Node* temp = head;
       head = head->next;
       temp->prev = NULL; //isolating the node 
       delete temp;

    }

}

void deleteFromTail(Node* &head, Node* &tail){
  if(tail == NULL){
    cout << "Node cannot be deleted " << endl;
  }
  else{
     //create a pointer
     Node* prevNode = tail->prev;
     prevNode->next = NULL;
     tail->prev = NULL;
     delete tail;
     tail = prevNode;
  }
}

void deleteNodeFromAnyPosition(Node* &head, Node* &tail, int pos){
  int len = findLength(head);
  //empty linked list
  if(head == NULL){
     cout << "Node cannot be deleted " << endl;
  }
  //single node 
  if(head == tail){
    Node* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
  }

  if(pos == 1){
    //delete from head 
    deleteFromHead(head, tail);
  }
//deleting from the tail position
  else if(pos == len+1){
    deleteFromTail(head, tail);
  }
  else{
  //deleting Node from the middle Position 
      //  Step1: setup prevNode,currNode,nextNode 
      Node* prevNode = NULL;
      Node* currNode = head;
      while(pos != 1){
        prevNode = currNode;
        currNode = currNode->next;
        pos--;
      }
      //Now set kardo next pointer 
      Node* nextNode = currNode->next;

      //update pointers;
      prevNode->next = nextNode;
      currNode->prev = NULL;
      currNode->next = NULL;
      nextNode->prev = prevNode;

  }


}


int main() {
  
 Node* head = NULL;
 Node* tail = NULL;

 insertAtHead(head, tail, 10);
 insertAtHead(head, tail, 20);
 insertAtHead(head, tail, 40);
 insertAtHead(head, tail, 30);


print(head);

cout << endl;
insertAtTail(head, tail, 3);
print(head);


cout << "Inserting any Position code starting from here : " << endl;
insertAtAnyPos(head, tail, 5, 1);
cout << "Inserting at head " << endl;
print(head);
cout << endl;
cout << "Inserting at tail " << endl;
insertAtAnyPos(head, tail, 50 , 6);
print(head);

cout << endl;
cout << "Inserting at Middle " << endl;
insertAtAnyPos(head, tail, 500 , 4);
print(head);

deleteFromHead(head, tail);
cout << endl;
cout << "Deleting the Node from head position " << endl;
print(head);

cout << endl;
cout <<"Deleting from tail " << endl;
deleteFromTail(head, tail);
print(head);

cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);

cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);

cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);

cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);

// cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);

cout << endl;
cout << "Deleting the Node from any position " << endl;
deleteNodeFromAnyPosition(head, tail, 1);
cout << "Length of Node is: " << findLength(head) << endl;
print(head);

  return 0;
}
