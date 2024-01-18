
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& inorder){
      if(root == NULL){
          return;
      }
    //  L
    storeInorder(root->left, inorder);
      
    // N
    inorder.push_back(root->val); //push back ek hi argument leta hai ye galti ki thi
  
    storeInorder(root->right, inorder);




    }


    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        storeInorder(root, inorder);
     
       int s = 0;
       int e = inorder.size()-1;
       
       while(s < e){
         int sum = inorder[s]+inorder[e];
          
          if(sum == k){
              return true;
          }
          else if(sum > k){
              e--;
          }else if(sum < k){
              s++;
          }

       }
       return false;


    }
};
