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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        // Moris Traversal 
        TreeNode* curr = root;
        while(curr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }

           else{
                // if curr->left not null, find predecessor in right 
            TreeNode* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            //if pred is not null, then make connection from curr and move left;
            if(pred->right == nullptr){
               pred->right = curr;
               curr = curr->left;
            }
            else{
                // pred is not null remove connection from curr and move right
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }

           }
        }
        return ans;
    }
};
