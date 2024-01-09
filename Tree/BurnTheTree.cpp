//User function Template for C++

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
class Solution {
  public:
    Node* makeNodeToParentMapAndFindTargetNode(Node* root,unordered_map<Node*,Node*>
    &parentMap, int target){
        // Using level Order Traversal 
        queue<Node*>q;
        Node* targetNode = 0; //pointing to null in starting 
        q.push(root);
        parentMap[root] = 0; //root ka parent null hoga 
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if(front->data == target){
                targetNode = front; 
            }
            if(front->left){
                q.push(front->left);
// ex 2 is the left child that we are pushing so in corresponding to that we are pusing
// 1 also 
             parentMap[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
// ex 3 is the right child that we are pushing so in corresponding to that we are pusing
// 1(parent) also 
             parentMap[front->right] = front;
            }
            
        }
        return targetNode;
    }
    
    int burnTheTree(Node* targetNode, unordered_map<Node*,Node*>&parentMap){
        // agar fire aage spread hoti then only we can increment the time 
        unordered_map<Node*,bool>isBurn; //
        queue<Node*>q; //currently set on fire ko save karke rakhegi
        int T = 0;
        q.push(targetNode);
        isBurn[targetNode] = 1; //it means targetNode is Burned 
        while(!q.empty()){
            int size = q.size(); //tell the size of current Node burning 
            bool isFireSpread = 0;
            // sari nodes simultaneous burn ho rhi hai so we will use the loop
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                
                if(front->left && !isBurn[front->left]){
                    q.push(front->left);
                    isBurn[front->left] = 1;
                    isFireSpread = 1;
                }
                 if(front->right && !isBurn[front->right]){
                    q.push(front->right);
                    isBurn[front->right] = 1;
                    isFireSpread = 1;
                }
                //agar parent hai to uspar bhi fire spread hogi 
                if(parentMap[front] && !isBurn[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurn[parentMap[front]] = 1;
                    isFireSpread = 1;
                }
            }
 // jab sari node burn ho jai ge tabhi time ko increment karenge 
            if(isFireSpread) ++T;
            
        }
        return T;
    }
    
    
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parentMap; //storing Node to parent child
        Node* targetNode = makeNodeToParentMapAndFindTargetNode(root, parentMap, target);
// to burn the tree we want the targetNode from where we have to start with parent map
        return burnTheTree(targetNode, parentMap);
    }
};
