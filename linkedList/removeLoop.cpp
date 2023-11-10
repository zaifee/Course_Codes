#include <iostream>
using namespace std;
class Node{
public:
int data;
Node *next;//yaha int nhi Node* aayega 

Node(){
  this->next = NULL;
}
Node(int data){
  this->data = data;
  this->next = NULL;
}
~Node(){
  cout << "Dtor called " << endl;
}





};

    void removeLoop(Node *head) {
    
        Node* fast = head;
        Node* slow = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            if (fast == slow) {
                break;
            }
        }
       

        // Loop se bahar ayye ho to slow and fast mil chuka hoga
        slow = head;

        // Slow and fast 1 step move karo tab tak wo meet na kare
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        
        
        Node* startingPointOfLoop =  slow; // Return the data of the node where the loop is found.

        Node*  temp = slow;
        while(temp->next != startingPointOfLoop){
          temp = temp->next;

        }
        //pata gya konsi node loop create kar rahe hai to use null mark kar diya 
         temp->next = NULL;  //yaha galti ki thiv
    }


void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
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

   
int main() {
  
  Node* head = NULL;
  Node* tail = NULL;

 insertAtHead(head, tail, 50);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 10);
  tail->next = head->next;

removeLoop(head);

  print(head);

  return 0;
}
