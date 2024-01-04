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
        bool leftToRightDirec = true;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
 // yaha me pata hona chahiye hammre queue me kitne element hai tu uske according hmm apna vector banai ge 
            int width = q.size();
//ab mujhe pata chal gya queue me ustime kitne element hai to leftright fill karna hoga ans me 0 to size karoga or rightoleft ke liye size-1 se 0 tak 
         vector<int>oneLevel(width); //utne size ka vector allocate kar diya
         for(int i=0; i<width; i++){
             TreeNode* front = q.front(); q.pop();
             int index = leftToRightDirec ? i : width-i-1; 
            //  width-i-1 means filling value from right to left;
            oneLevel[index] = front->val; //putting value in the vector
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }

           
         }
          // toggle the direction 
            leftToRightDirec = !leftToRightDirec;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};
