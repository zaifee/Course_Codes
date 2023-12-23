
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftSubTree = maxDepth(root->left);
        int rightSubTree = maxDepth(root->right);
        int height = max(leftSubTree, rightSubTree) + 1;
        return height;
    }
};
