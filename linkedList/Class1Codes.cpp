#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

//def ctor 
Node(){
    cout << "Def ctor called " << endl;
    this->next = NULL;
}

//param ctor called 
Node(int data){
    // cout << "Param ctor called " << endl;
    this->data = data;
    this->next = NULL;
}





    
};

    
void printLL(Node* head){
   Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        
        temp = temp->next;
    }
    
    cout << endl;
    
}   



//creating tail explicitly 
void createTail(Node* head, Node* tail){
    
    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    tail = temp;
}



int getLength(Node* head){
     int cnt = 0;
     
     Node* temp = head;
     while(temp != NULL){
         cnt++;
         temp = temp->next;
     }
     
     
     return cnt;
}


void insertAtHead(Node* &head, Node* &tail, int data){
    //In case of empty linked list 
    if(head == NULL){
        //create a new Node 
        Node* temp = new Node(data);
        //update the head pointer
        head = temp;
        tail = temp;
        
        //We also have to handle the case of in case of single element in a linked list 
        
    }
    
    
  else{
      
      
    // In case of empty linked list 
    Node* newNode = new Node(data);
    
    //points to head pointer
    
    newNode->next = head;
    //update the head pointer
    
    head = newNode;
    }
}


void insertAtTail(Node* &head, Node* tail, int data){
    if(tail == NULL){
        //create a new Node 
        Node* temp = new Node(data);
        
        //Points the tail pointer to new node 
        //head and tail dono Null ko point kar rahe honge in case of Null 
        //in case of single linkedlist head and tail ek hi jagah point karenge;
        //so dono ko updata karna padega 
        tail = temp;
        head = temp;
        
    }
    
    else{
        //in case of Non-empty linked list 
        // 1. Create a new Node 
        Node* newNode = new Node(data);
        
        // 2 . Update the tail poistion 
        tail->next = newNode;
        
        // 3.update tail pointer 
        tail = newNode;
        
    }
}

void insertAtAnyPosition(Node* &head, Node* &tail, int data, int Position){
   
    
    int len = getLength(head);
   
    if(Position == 1){
        insertAtHead(head, tail, data);
    }
    if(Position > len+1){
        cout << "Value cannot be inserted at this Position " << endl;
    }
    else if(Position == len){
        insertAtTail(head, tail, data);
    }
    else{
        
        //insert node at middle of linked list 
        
        //create a new Node 
        Node* newNode = new Node(data);
        
        
        // ṣtep 2: traverse prev// curr at poistion 
        Node* prev  = NULL;
        Node* curr =  head;
        while(Position != 1){
            prev = curr;
            curr = curr->next;
            Position--;
        }
        
        //forget last two steps -- yaha galti ki thi ye steps nhi likhe 
        prev->next = newNode;
        newNode->next = curr;
        
    }
}




int main(){
    
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    // printLL(head);
    
    // insertAtAnyPosition(head, tail, 1, 1);
    // printLL(head);//insert at head wala case 
    
    insertAtAnyPosition(head, tail, 2, 7);
    printLL(head);
    
    
    
    
    
    
    // Node a;
    
    // Node *first = new Node(3);
    // Node* second = new Node(4);
    // Node* third = new Node(6);
    // Node* fourth = new Node(7);
    
    // Node* head = first;
    // Node* tail = fourth;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = NULL;
    
    // printLL(head);
    
    // //  printLL(head);
    // cout << "Length of Linked list is: " <<getLength(head) << endl;
    
    // insertAtHead(head,tail, 200);
    // //after inserting node at head;
    // printLL(head);
    
    // cout << "Linked List after Insert at tail " << endl;
    // insertAtTail(head, tail, 500);
    // printLL(head);
   
    
    return 0;
}
