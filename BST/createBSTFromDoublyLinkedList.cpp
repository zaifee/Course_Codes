/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    
    
};

Node* insertIntoBST(Node* root, int data){
  if(root == NULL){
    root = new Node(data);
    return root;
  }
  if(data > root->data){
    root->right = insertIntoBST(root->right, data);
  }
  else{
    root->left = insertIntoBST(root->left, data);
  }
  return root; //pichli bar ye bhul gya tha
}

void createBST(Node* &root){
  int data;
  cout << "Enter the data : " << endl;
  cin>> data;
  while(data != -1){
    root = insertIntoBST(root, data);
    cin >> data; //aage wali node ke liye data hai;
  }
}



Node* createBSTFromDLL(Node* &head, int n){
    //n represents no. of nodes in dobly linked list 
    if(head == NULL || n <= 0){
        return NULL;
    }
    
    //L 
    Node* leftSubTree = createBSTFromDLL(head, n/2);
    
    //N 
    // current node ko head bana lo 
    Node* root = head;
    // left leftSubTree ban chuka hai use laga do 
    root->left = leftSubTree;
    //ye bhul jate hai 
    head = head->right;
    
    //right righSubtree banawa lo recursion se 
    Node* rightSubTree = createBSTFromDLL(head, n-n/2-1);
    
    root->right = rightSubTree;
    return root;
    
}




void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
    
     auto front = q.front();
     q.pop();
     
     
     if(front == NULL){
         cout << endl;
         if(!q.empty()){
             q.push(NULL);
         }
     }
     
     else{
         cout << front->data << " ";
         if(front->left){
             q.push(front->left);
         }
         if(front->right){
             q.push(front->right);
         }
     }
    }
    
}



int main()
{
    // Node* root = createBST();
    // Node* root = NULL;
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;
    
    Node* head = first;
    
    Node* root = createBSTFromDLL(head, 3);
    // levelOrderTraversal(root);
    
    
    
    
    
    
    
    int inorder[] = {10,30,20,50,60,70};
    levelOrderTraversal(root);

    return 0;
}
