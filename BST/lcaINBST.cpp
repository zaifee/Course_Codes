/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        // case 1: p and q both comes in left subtree of root Node
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        // case2: p and q both comes in right subtree of root Node
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }
// case 3: p is in left subtree of leftNode and q comes in right subtree of rootNode
       if(p->val < root->val && q->val > root->val){
           return root;
       }
    //    case4: q is in left subtree of rootNode && q is on right subtree of root Node
       if(q->val < root->val && p->val > root->val){
           return root;
       }
       return root;
    }
};
