/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;

Node(int val){
    data = val;
    left = NULL;
    right = NULL;
}

};
Node* createTree(){
    cout << "Enter any value for the Node : " << endl;
    int data;
    cin >> data;
    
    if(data == -1){
        return NULL;
    }
    //root create karlo 
    Node* root = new Node(data);
    //left subtree create karlo 
    root->left = createTree();
    
    //right subtree 
    root->right = createTree();
    
    return root;
    
}
void levelOrderTravesal(Node* root){
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty() > 1){
        Node* front = q.front(); //front ek Node hai galti ki int front likha rha tha 
        q.pop();
        
        
        if(front == NULL){
         cout << endl;
        if(!q.empty()){
             q.push(NULL);
        }
            
        }
        
        else{
        
        //Valid Node wala case 
        
        cout << front->data << endl;
        
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
        
        
        }
    }
   
}







int main()
{
   Node* root = createTree();
//   cout << root->data << endl; 
  cout << "Level Order Traversal ";
  levelOrderTravesal(root);
  cout << endl;
  
    return 0;
}
