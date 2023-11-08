

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
      Node* ptr = new Node(data);
      
      //update the pointer
        head=ptr;
        tail=ptr;
    }
    
    else{
        //1. create a new Node 
        
        Node* temp = new Node(data);
        
        temp->next = head;
        
        head = temp;
        
    }
    
    
}  

void printLL(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp->data<<"->";
        temp = temp->next;
    }
    
}
    
    
    
   void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
      
      //create a new node 
      Node* ptr = new Node(data);
      
      //update the pointer
        head=ptr;
        tail=ptr;
    }
    
    else{
        //1. create a new Node 
        
        Node* temp = new Node(data);
        
        tail->next = temp;
        
        tail = temp;
    }
    
    
}  

void insertAtTail(Node* &head, Node* &tail){
    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    tail = temp;
}
 
 int getLength(Node* &head){
     Node* temp = head;
     int cnt = 0;
     while(temp != NULL){
         cnt++;
         temp = temp->next;
     }
     return cnt;
 }    
 
void insertAtAnyPosition(Node* &head, Node* &tail, int data, int poistion){

    // if poistion == 1 head wala case hoga 
    int len = getLength(head);
    
    if(poistion == 1){
        insertAtHead(head, tail, data);
    }
    
    else if(poistion == len){
        insertAtTail(head, tail, data);
    }
    
    else{
        
        //creating a node 
        Node* temp = new Node(data);
        
        
        
        //middle me insert karna hai 
        //taking two pointers so that hmm us position tak pouchuch sake
        Node* prev = NULL;
        Node* curr = head;
        
        while(poistion != 1){
            prev = curr;
            curr = curr->next;
        }
        
        //combine rahe hai; nodes ko
        prev->next = temp;
        temp->next = curr;
        
    }
    
   
} 

void deleteAnyNode(Node* &head, Node* &tail, int position){
    
    int len = getLength(head);
    if(head == NULL){
        cout << "Node can't be deleted: "<< endl;
    }
    if(tail == NULL){
        //node nhi hai hamare pass-- 
        //single wala case 
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    else if(position == 1){
        //head wala case 
        
        Node* temp = head;
        head = temp->next;
        temp->next = NULL; //isolating the Node which is going to be deletd;
        delete temp;
    }
    
    else if(position == len){
        //last wali node ka case 
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        
        //ab hmm tail par pohuch gye hoge 
        //isolate the node - so null kardo last se pehli node ko 
        prev->next = NULL;
        
        delete tail;
        
        tail= prev;
    }
    else{
        
        //middle se delete karna hai  
        Node* prev = NULL;
        Node* curr = head;
        
        while(position != 1){
              prev =curr;
              curr = curr->next;
              position--; //phir se bhul gya tha ye likhna 
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
    }
}
 

 
    
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 100);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 300);
    insertAtHead(head, tail, 400);
    insertAtHead(head, tail, 500);
    insertAtHead(head, tail, 600);
    insertAtHead(head, tail, 700);
    insertAtHead(head, tail, 800);
    insertAtTail(head, tail, 1000);
    
    
    // printLL(head);
    
    // insertAtAnyPosition(head, tail, 1, 1);
    // printLL(head);
    
    // cout << endl;
    
    // insertAtAnyPosition(head, tail, 3, 4);
    printLL(head);
    deleteAnyNode(head, tail, 1);
    cout << endl;
    cout << "Printing linked list after deleting from head " << endl;
    printLL(head);
    cout << endl;
    cout << "Printing linked list after deleting from tail " << endl;
    deleteAnyNode(head, tail, 8);
    printLL(head);
    cout << endl;
    cout << "Printing Linked list from the Middle : " << endl;
    deleteAnyNode(head, tail, 3);
    printLL(head);

    return 0;
}
