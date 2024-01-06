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
    int ans = 0;
    void pathFromRoot(TreeNode* root, long long targetSum){
        if(!root) return;

        if(targetSum == root->val){
            ++ans;
        }
        //preOrder traversal laga do left or right ke liye 
        pathFromRoot(root->left, targetSum-root->val);
        pathFromRoot(root->right, targetSum-root->val); 


    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
           pathFromRoot(root, targetSum); //ek bar root ko man kar check karlo
        //    now har ek node ko root manke check karlo using preOrder traversal
           pathSum(root->left, targetSum);
           pathSum(root->right, targetSum);
        }
        return ans;
        
    }
};
