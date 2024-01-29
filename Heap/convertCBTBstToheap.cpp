#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;

Node(int val): data(val), left(NULL), right(NULL) {};

};

Node* insertIntoBST(Node* root, int data){
  if(root == NULL){
    root = new Node(data);
    return root;
  }
  // Now insert into left and right 
  if(data > root->data){
    root->left = insertIntoBST(root->left, data);
  }
  else if(data < root->data){
    root->right = insertIntoBST(root->right, data);
  }
  return root;
}

void createBST(Node* root){
  int data;
  cout << "Enter the data : " << endl;
  cin >> data;
  while(data != -1){
    root = insertIntoBST(root, data);
    cout << "Enter the data " << endl;
    cin >> data; //for the next nodes 
  }

}

// void levelOrderTraversal(Node* root){
//   if(root == NULL) return;
//   queue<Node*>q;
//   q.push(root);
//   q.push(NULL);

//   while(!q.empty()){
//     Node* front = q.front();
//     q.pop();

//     if(front == NULL){
//       cout << endl;
//       if(!q.empty())
//         q.push(NULL);
//     }
//     else{
//      cout << front->data << " ";
//       if(front->left)
//         q.push(front->left);

//       if(front->right)
//       q.push(front->right);
      
//     }
//   }

// }


void storeInInorder(Node* root, vector<int>&in){
  if(root == NULL) return;

  storeInInorder(root->left, in);
  in.push_back(root->data);
  storeInInorder(root->right, in);
}

void modifyingTreeNodeUsingPostOrder(Node* root, vector<int>in, int index){
  if(root == NULL){
    return;
  }
  modifyingTreeNodeUsingPostOrder(root->left, in, index);
  modifyingTreeNodeUsingPostOrder(root->right, in, index);
  root->data =  in[index];
  index++;
}

Node* convertBSTAndCBTToMaxHeap(Node* root){
 
  vector<int>in;
  storeInInorder(root, in);
  int index = 0;
  modifyingTreeNodeUsingPostOrder(root, in, index);

  return root;
}



int main() {
  
 Node* root = NULL;
 createBST(root);
 levelOrderTraversal(root);



  
  return 0;
}
