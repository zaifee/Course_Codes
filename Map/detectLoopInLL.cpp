Using Map based approach: 
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        unordered_map<Node*, bool>mapping;
        Node* temp = head;
        while(temp != NULL){
            
            if(mapping.find(temp) != mapping.end()){
                 return true;
            }
            else{
                //Node not visited 
                mapping[temp] = true;
            }
            temp = temp->next;
        }
        return false;
    }
};
