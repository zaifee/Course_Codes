

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node* root, int &k, int node, int &ans){
    if(root == NULL) return 0;
    
    if(root->data == node) return root;
    if(ans != -1){
        //it means ans mil chuka hai aage mat jao 
        return root; //optimization
    }
    
    
    auto lh = solve(root->left, k, node, ans);
    auto rh = solve(root->right, k, node, ans);
    
    if(!lh && !rh) return 0; //ye condition bhul gya tha
    k--;
    if(k == 0){
        ans = root->data;
    }
    
    if(lh && !rh) return lh;
    else if(!lh && rh) return rh;
    else return root;
}
int kthAncestor(Node *root, int k, int node)
{
     int ans = -1;
     solve(root, k, node, ans);
     return ans;
}
