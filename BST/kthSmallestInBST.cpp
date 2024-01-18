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
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL){
            return -1;
        }
        // L
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1){
            return leftAns;
        }
    //  N
// Wrong answer isliye aaraha hai bcz hmmne k ki value ka track nhi rakha so k ko by reference pass karo 
      k--;
      if(k == 0){
          return root->val;
      }

    //   R 
    int rightAns = kthSmallest(root->right, k);
//yaha galti ki thi -1 ke equal check na lagao simply return kardo  
        return rightAns;

    }
};
