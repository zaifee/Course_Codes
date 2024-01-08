//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int>getMaximumSumOFAdjacentNodes(Node* root){
        if(!root) return{0,0};
        
        auto left = getMaximumSumOFAdjacentNodes(root->left);
        auto right = getMaximumSumOFAdjacentNodes(root->right);
        
        // sum including the root Node 
        // we will include the second side of tree bcz we are not considering the
        // sum of first pair side bcz first pair represent the sum of root node ke 
        // child
        int a = root->data + left.second + right.second;
        
        // excluding the root Node -- so will take maximum of left handside and 
        // right hand side so that all nodes of same parent will not be selected
        
        int b = max(left.first, left.second) + max(right.first, right.second);
        return {a,b};
    }
    int getMaxSum(Node *root) 
    {
       auto ans = getMaximumSumOFAdjacentNodes(root);
       return max(ans.first, ans.second);
    }
};
