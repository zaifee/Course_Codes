/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
   void fun(Node* root, bool &ans, unordered_map<int,bool>&visited){
       if(root == 0) return;
       visited[root->data] = 1;
       //check leaf node pe data lag sakta hai ya nhi 
       if(root->left == 0 && root->right == 0){
           int xplus1 = root->data+1;
           int xminus1 = root->data-1 == 0 ? root->data : root->data-1;
        //   yaha galti ki thi map walli condition me && aayeg naki or
           if(visited.find(xplus1) != visited.end() && visited.find(xminus1) != visited.end()){
               ans = true;
               return;
           }
       }
       fun(root->left, ans, visited);
       fun(root->right, ans, visited);
   }
    bool isDeadEnd(Node *root)
    {
        bool ans = false;
        unordered_map<int,bool>visited;
         fun(root, ans, visited);
         return ans; //yaha galti ki thi
    }
};
