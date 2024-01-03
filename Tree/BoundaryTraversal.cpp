class Solution {
public:
     void printLeftBoundary(Node* root, vector<int>&ans){
         if(root == NULL){
             return;
         }
         if(root->left == NULL && root->right == NULL){
             return;
         }
         ans.push_back(root->data);
         if(root->left != NULL){
             
             printLeftBoundary(root->left, ans);
            
         }
         else{
             printLeftBoundary(root->right, ans);
         }
     }
     
     void printLeafBoundary(Node* root, vector<int>&ans){
         if(root == NULL){
             return;
         }
         if(root->left == NULL && root->right == NULL){
             ans.push_back(root->data);
         }
         printLeafBoundary(root->left, ans);
         printLeafBoundary(root->right, ans);
         
     }
     
     void printRightBoundary(Node* root, vector<int>&ans){
         if(root == NULL){
             return;
         }
         if(root->left == NULL  && root->right == NULL){
             return;
         }
         if(root->right != NULL){
             printRightBoundary(root->right , ans);
         }
         else{
             printRightBoundary(root->left, ans);
         }
         ans.push_back(root->data);
     }
     
     void printBoundaryTraversal(Node* root, vector<int>&ans){
         if(root == NULL){
             return;
         }
         ans.push_back(root->data);
         printLeftBoundary(root->left, ans);
         printLeafBoundary(root->left, ans);
         printLeafBoundary(root->right, ans);
         printRightBoundary(root->right, ans);
         
     }
     
     
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        printBoundaryTraversal(root, ans);
        return ans;
    }
};

