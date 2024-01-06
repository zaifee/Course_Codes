//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    pair<int,int> height(Node* root){
        if(!root) return{0,0};
        
        auto lh = height(root->left);
       auto rh = height(root->right);
        int sum = 0; 
        sum += root->data; //ye bhul gya tha
        //first represent height and second represent sum so we are using pair
        //now check karlo 
        // kya dono side se left heigh and right height equal hai 
        //equal ho to uska sum consider karo jiski height badi ho
        
        if(lh.first == rh.first){
            sum += lh.second > rh.second ? lh.second : rh.second;
        }
        else if(lh.first > rh.first){
            sum += lh.second;
        }
        else{
            //right ki heigh badi hai 
            sum += rh.second;
        }
        
        return {max(lh.first, rh.first)+ 1, sum}; 
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        auto ans = height(root);
        return ans.second;
    }
};
