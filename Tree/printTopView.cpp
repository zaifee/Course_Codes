/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
void printTopView(Node* root, vector<int>&ans){
   if(root == NULL){
     return;
   }
  map<int,int>hdToNodeMap;
  queue<pair<Node*,int>>q;
  // intially pushing root with there level 
  q.push(make_pair(root, 0));

  while(!q.empty()){
    pair<Node*,int>temp = q.front();
    q.pop();
    // Now taking out Node and int value separately 
    Node* frontNode = temp.first;
    int hd = temp.second;

    // check in map that the entry is exist or not 
    if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
      //if not exist, create a new entry in the map
      hdToNodeMap[hd] = frontNode->data;
    }

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

    vector<int> topView(Node *root)
    {
        vector<int>ans;
        printTopView(root, ans);
        return ans;
    }

};
