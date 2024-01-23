/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>ans;
        stack<Node*>sa,sb;
        Node* a = root1, *b = root2;
        while(a || b || !sa.empty() || !sb.empty()){
            while(a){
                // Inorder traversal 
                sa.push(a);
                a = a->left;
            }
            while(b){
                // Inorder traversal
                sb.push(b);
                b = b->left;
            }
            
            // compare karo dono ke elements or push kardo 
            if(sb.empty() || (!sa.empty() && sa.top()->data < sb.top()->data)){
                auto atop = sa.top();
                ans.push_back(atop->data);
                sa.pop();
                a = atop->right;
            }
            else{
                auto btop = sb.top();
                ans.push_back(btop->data);
                sb.pop();
                b = btop->right;
            }
        }
        return ans;
    }
};
