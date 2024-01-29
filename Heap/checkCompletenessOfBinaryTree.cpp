class Solution {
public:
 
    bool levelOrderTraversal(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        // q.push(NULL);
         bool nullFound = false;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                nullFound = true;
            }
            else{
               if(nullFound)
               return false;
           
                q.push(front->left);
                q.push(front->right);
            

            }
        }

        return true;
    }
    bool isCompleteTree(TreeNode* root) {
       
      return levelOrderTraversal(root);
    }
};
