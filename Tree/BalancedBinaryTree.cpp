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
   int height(TreeNode*  root){
       if(root == NULL){
           return 0;
       }

       int leftHeight = height(root->left);
       int rightHeight = height(root->right);
       int finalAns = max(leftHeight, rightHeight)+1;
       return finalAns;

   }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;  //root null hai to balance hai tree;
        }

        //1 case solve karo 
        int leftSubTreeHeight = height(root->left);
        int rightSubTreeHeight = height(root->right);
        int diff = abs(rightSubTreeHeight-leftSubTreeHeight);

        bool currNodeAns = (diff <= 1);

     //recursive call
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

//  Agar tino ans balance hai currNode,leftans, rightAns to entire tree balance hai
        if(currNodeAns && leftAns && rightAns){
            return true;
        }else{
            return false;
        }
    }
};
