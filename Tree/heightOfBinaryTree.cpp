
class Solution {
public:
    int maxDepth(TreeNode* root) {
       
    queue<TreeNode*>q;
    if(root == NULL){
        return 0; //ye condition bhul gye the
    }
    q.push(root);
    q.push(NULL);
    int count = 1;  //galti ki thi jitne null hai utne hi count hoga so
    //it will start from 1
    
    while(!q.empty()){
        TreeNode* front = q.front(); //front ek Node hai galti ki int front likha rha tha 
        q.pop();
        
        
        if(front == NULL){
         cout << endl;
        if(!q.empty()){
             count++;
             q.push(NULL);
        }
            
        }
        
        else{
        
        //Valid Node wala case 
        
        // cout << front->data << endl;
        
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
        
        
        }
    }
   
  return count;


    }
};
