//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    void printBottomView(Node* root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        map<int,int>hdToNodeMap;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // overwriting the Node value so that deeper Node come first
            hdToNodeMap[hd] = frontNode->data;
            
            //child dekhlo 
            if(frontNode->left != NULL){
                 q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, hd+1));
            }
            
        }
        
        for(auto it: hdToNodeMap){
            ans.push_back(it.second);
        }
    }
    
    
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        printBottomView(root, ans);
        return ans;
    }
};
