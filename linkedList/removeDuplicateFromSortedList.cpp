/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
        //empty linked list 
        if(head == NULL){
            return head;
        }
        //single Node
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp != NULL){

            if(temp->next != NULL && temp->val == temp->next->val){
                // remove the node 
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next; //saving the after nextNode wale pointet
                nextNode->next = NULL; //isolating the Node
                delete nextNode;

            }else{
                temp = temp->next;
            }
        }
        return head;

    }
};
