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
    vector<TreeNode*>ans;
    unordered_map<string,int>subTreeMap;
    string preorder(TreeNode* root){
        if(!root) return "N"; //N means null here means root node points to null
        string curr = to_string(root->val);
        string l = preorder(root->left);
        string r = preorder(root->right);
        string s = curr + "," + l + "," + r;
        if(subTreeMap.find(s) != subTreeMap.end()){
             if(subTreeMap[s] == 1){
                 ans.push_back(root);
             }
             subTreeMap[s]++;
        }
        else{
            subTreeMap[s] = 1;
        }
        return s; //returning total representation;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         preorder(root);
         return ans;
    }
};
