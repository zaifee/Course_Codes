//Back-end complete function Template for C++
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int val):data(val), left(0), right(0){};
   
};
class Solution{
    public:
    Node* insertInBST(Node* root, int val, int &succ){
        if(!root) return new Node(val);
         
         if(val >= root->data){ //value badi hai root ke data se root ke right me add karna hai
           root->right = insertInBST(root->right, val, succ);
             
         }
         else{
             //jab bhi left me jai ge succ choose hoga or least wala 
             succ = root->data;
              root->left = insertInBST(root->left, val, succ);
         }
        
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        Node* root = 0;
    
        for(int i=n-1; i>=0; i--){
            int succ = -1;
            root = insertInBST(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};
