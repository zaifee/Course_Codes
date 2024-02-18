*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        map<int, Node*>map;
        Node* curr = head1;
        
        //Hashed List 1
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        //Hashed List 1
        curr = head2;
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        Node* UnionList = NULL;
        curr = 0;
        //iterating over the map 
        for(auto it=map.begin(); it != map.end(); it++){
            if(!UnionList){
                UnionList = it->second; //first element of list
                curr = UnionList; //making a head pointer 
            }
            else{
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = 0;
        return UnionList;
        
        
        
    }
};
