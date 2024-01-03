

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
  void printLeftView(Node* root, vector<int>&ans,int level){
      if(root == NULL){
          return;
      }
      
      if(ans.size() == level){
          ans.push_back(root->data);
      }
      
      printLeftView(root->left, ans, level+1);
      printLeftView(root->right, ans, level+1);
      
      
  }
  
  
vector<int> leftView(Node *root)
{
    vector<int>ans;
    int level = 0;
    printLeftView(root, ans, level);
    return ans;
}
