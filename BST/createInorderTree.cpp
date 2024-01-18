#include <iostream>
#include <queue>
using namespace std;
class Node{
 public:
int data;
Node* left;
Node* right;

Node(int data){
this->data = data;
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


// void levelOrderTraversal(Node* root){
//   if(root == NULL){
//     return;
//   }
//   queue<Node*>q;
//   q.push(root);
//   while(!q.empty()){
//     Node* temp = q.front();
//     q.pop();

//     if(temp == NULL){
//       cout << endl;
//       if(!q.empty()){
//         q.push(NULL);
//       }
//     }
//     else{
//       cout << temp->data << " ";
//       if(temp->left)
//         q.push(temp->left);
//       if(temp->right)
//         q.push(temp->right);
      
//     }
//   }
  
// }

void levelOrderTraversal(Node* root){
  if(root == NULL)
    return;
  
  queue<Node*> q;
  q.push(root);
  q.push(NULL); //Null push nhi kara tha isliye level wise print nhi ho rha tha
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    if(temp == NULL){
      cout << endl;
      if(!q.empty())
        q.push(NULL);
      
    }
    else{
      cout << temp->data << " ";

      if(temp->left)
        q.push(temp->left);

      if(temp->right)
        q.push(temp->right);
    }
  }
}


void preOrderTraversal(Node* root){
  if(root == NULL){
    
    return;
  }
  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}
void inOrderTraversal(Node* root){
  if(root == NULL){
    
    return;
  }
  
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}


void postOrderTraversal(Node* root){
  if(root == NULL){
    
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

Node* minValueInBST(Node* root){
    if(root == NULL){
        cout << "No minimum value exist: " << endl;
        return NULL;
    }
    
    Node* temp = root;
    
    //min value exist in BST in leftMostOrder of tree
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValueInBST(Node* root){
    if(root == NULL){
        cout << "No maximum value exist: " << endl;
        return NULL;
    }
    
    Node* temp = root;
    
    //max value exist in BST in rightMostOrder of tree
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    
    if(root->data == target){
        return true;
    }
    
    //now target ya to left me hoga ya right me ya hoga hi ni --
    bool leftAns = false; //store the left ans is true or false initially assuming it is false;
    bool rightAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right, target);
    }
    else{
        leftAns = searchInBST(root->left, target);
    }
    
    return leftAns || rightAns; 
}

Node* deleteFromBST(Node* root, int target){
    if(root == NULL)
        return NULL;
    
    
    //4 cases will be there 
    if(root->data == target){
        
    
    //1 case leaf node delete karni hai
     if(root->left == NULL && root->right == NULL){
         delete root;
         return NULL;
     }
    //  2 case -- left not null and right null hai
    else if(root->left != NULL && root->right == NULL){
        Node* childSubTree = root->left; //baki node store kar rahe hai delete se pehle
        delete root;
        return childSubTree;
    }
    // 3 case -- right not null and left null hai
    else if(root->left == NULL && root->right != NULL){
        Node* childSubTree = root->right; //baki node store kar rahe hai delete se pehle
        delete root;
        return childSubTree;
    }
    else{
        //left subtree bhi not null hai or right subtree bhi not null hai 
        //left node ki maximum value le aao 
        Node* maxi = maxValueInBST(root->left);
        //root->data ko data ko usse replace kardo 
        root->data = maxi->data;
        
        //delete old maxi in left subtree 
    root->left = deleteFromBST(root->left, maxi->data); //this recursive call return something so we will attach this in left 
    
    }
        
        
    }
    
    else{
        if(root->data > target)
            root->left = deleteFromBST(root->left, target); //yaha galti return kar rhe the
        
        else
            root->right = deleteFromBST(root->right, target); //yaha galti ki return kar rhe hai
        
    }
    return root;
    
}
Node* createTreeFromInorder(int inorder[], int s, int e){
    if(s > e) return NULL;
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);
    
    //recursive call 
    root->left = createTreeFromInorder(inorder, s, mid-1);
    root->right = createTreeFromInorder(inorder, mid+1, e);
    
    return root;
}





int main(){

//   Node* root = NULL;
//   createBST(root);
//   levelOrderTraversal(root);
//   cout << endl;
//   cout << "InOrder: ";
//   inOrderTraversal(root);
//   cout << endl;
//   cout << "preOrder: ";
//   preOrderTraversal(root);
//   cout << endl;
//   cout << "postOrder: ";
//   postOrderTraversal(root);
// cout << endl;
//  cout << "Min Value in the BST is: " << endl;
// Node* minNode =  minValueInBST(root);
// if(minNode == NULL){
//     cout << "There is no Minimum Node present as tree empty: " << endl;
// }
// else{
//     cout << "Min value: " << minNode->data << endl;
// }

// Node* maxNode = maxValueInBST(root);
// if(maxNode == NULL){
//     cout << "There is no Maximum Node present as tree empty " << endl;
// }
// else{
//     cout << "Max value: " << maxNode->data << endl;
// }
// cout << endl;

/*
int t; 
cout << "Enter the target: " << endl;
cin >> t;
while(t != -1){
  
  bool ans = searchInBST(root, t);
  if(ans == true){
      cout << "Found" << endl;
  }
  else{
      cout << "Not Found " << endl;
  }
  cout << "Enter the target " << endl;
  cin >> t;
}
 */
// int target;
// cout << "Enter the value of target: " << endl;
// cin >> target;

// while(target != -1){
//     root = deleteFromBST(root, target);
//     cout << endl;
//     cout << "Printing the value of levelOrderTraversal " << endl;
//     levelOrderTraversal(root);
    
//     cout << "Enter the value of target: " << endl;
//     cin >> target;
// }
int inorder[] = {10,20,30,40,50,60,70};
int size = sizeof(inorder)/sizeof(int);
int s= 0;
int e = size-1;
Node* ans = createTreeFromInorder(inorder, s, e);
levelOrderTraversal(ans);
 
  return 0;
}
