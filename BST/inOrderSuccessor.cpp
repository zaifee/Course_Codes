/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node* succ = 0;
       Node* curr = root;
       while(curr){
        //   curr ka data bada hai to left me jai ge
           if(curr->data > x->data){
               succ = curr;
               curr = curr->left;
           }
           else{
               curr = curr->right;
           }
       }
       return succ;
    }
};
