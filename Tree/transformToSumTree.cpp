
class Solution {
  public:
    int sum(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            //it means it is a leaf node 
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        //find lsum or rsum 
        int lsum = sum(root->left);
        int rsum = sum(root->right);
        int currData = root->data;
        root->data = lsum+rsum; //root->data aayega naki new var me same karna or right sum
        return root->data+currData;
    }
    
    void toSumTree(Node *node)
    {
        sum(node);
    }
};
