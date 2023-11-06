/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

~Node(){
    cout << "Dtor called " << this->data << endl;
}

    
};

int getLength(Node* &head){
    int cnt = 0;
    Node* temp  = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


void deleteAnyNode(Node* &head, Node* &tail, int position){
    int len = getLength(head);
   if(head == NULL){
       cout << "Value cannot be deleted " << endl;
   }
   
   if(head == tail){
       //single element 
       Node* temp = head;
       delete temp;
       head = NULL;
       temp = NULL;     
       return;  
   }
   
   
   
   
   
   //single ll
   if(position == 1){
      //first node ko delete kardo 
       Node* temp = head;
       
       head = head->next;
       
       temp->next = NULL;
       delete temp;
       
   }
   
   else if(position == len){
       //last node ko delete kardo  
       
       Node* prev = head;
       while(prev -> next != tail){
           prev = prev->next;
       }
       
       //prev node ka link null karo 
       prev->next = NULL;
       
       //delete NULL 
       delete tail;
       
       //node delete karo 
       tail = prev;
   }
   
   else{
       // middle me koi node ko delete kardo 
       
       
    //   Step1: Set up prev/curr pointers
    
      Node* prev = NULL;
      Node* curr = head;
      while(position != 1){
          position--;
          prev = curr;
          curr = curr->next;
      }
      
      //step 2: prev and current pointers updation 
      prev->next = curr->next;
      //Node isloate kar do 
      curr->next = NULL;
      
      delete curr;
       
   }
     
}
void insertAthead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        
        //create a node 
        Node* temp = new Node(data);
        
        head = temp;
        tail = temp;
       
    }
    else{
        //create a new node 
        Node* newNode = new Node(data);
        
        newNode->next = head;
        
        //update the pointer 
        head = newNode;
    }
    
    
}


void printNode(Node* head){
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAthead(head, tail, 20);
    insertAthead(head, tail, 10);
    insertAthead(head, tail, 30);
    insertAthead(head, tail, 40);
    
    // printNode(head);
    
    // deleteAnyNode(head, tail, 1);
    cout << "Printing LL after deleting the value from it: "<< endl;
    // printNode(head);
    
    deleteAnyNode(head, tail, 4);
    deleteAnyNode(head, tail, 3);
    deleteAnyNode(head, tail, 2);
    cout << "Before deleting head ki value " << head->data << endl;
    cout << "Before deleting tail ki value " << tail->data << endl;
    deleteAnyNode(head, tail, 1);
    printNode(head);
    cout << "After deleting head ki value " << head->data << endl;
    cout << "AFter deleting tail ki value " << tail->data << endl;
    
    printNode(head);
    return 0;
}
