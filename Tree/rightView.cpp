class Solution {
public:
    void printRightView(TreeNode* root, vector<int>&ans, int level){
        if(root == NULL){
            return;
        }
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        //recursive call as it is a right view so right call first 
        printRightView(root->right, ans, level+1);
        printRightView(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        printRightView(root, ans, level);
        return ans;
    }
};
