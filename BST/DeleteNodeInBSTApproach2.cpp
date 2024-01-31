/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return 0;

        if(root->val == key){
           
        //    if leaf Node 
          if(!root->left && !root->right){
              delete root;
              return 0;
          }
         else if(!root->left){
             auto temp = root;
             root = root->right;
             delete temp;
             return root;

         }
          else if(!root->right){
             auto temp = root;
             root = root->left;
             delete temp;
             return root;

         }
         else{
            //  both are not null left and right
              auto rscan = root->right;
              while(rscan->left)
              rscan = rscan->left;
              rscan->left = root->left; //root ke left pe rscan ka left laga diya 
              auto temp = root;
              root = root->right;
              delete temp;
              return root;
                  
              

         }

        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
