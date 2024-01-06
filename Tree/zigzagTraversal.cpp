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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool leftToRightDirect = true;
        if(!root) return ans;
        queue<TreeNode*>q; //queue bhul gya tha
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            vector<int>oneLevel(width);
            for(int i=0; i<width; i++){
                TreeNode* front = q.front(); q.pop();
                //insert kaha karna hai wo nikal liya 
                int index = leftToRightDirect ? i : width-i-1;
                oneLevel[index] = front->val;

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            // toggle the direct
            leftToRightDirect = !leftToRightDirect;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};
