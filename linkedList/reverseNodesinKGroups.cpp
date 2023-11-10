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
 int getLength(ListNode* head){
     ListNode* temp = head;
     int len = 0;
     while(temp != NULL){
         len++;
         temp = temp->next;
     }
     return len;
 }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //empty Node
        if(head == NULL){
            return head;
        }
        //single node
        if(head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int pos = 0;
        int len = getLength(head);
        if(len < k){
            return head;
        }
        while(pos < k){
            nextNode = curr->next;
            curr->next = prev; //yaha ye galit ki curr->prev likh diya tha
            prev = curr;
            curr = nextNode;
            pos++; //ye bhul gya tha to dikkat hoi thi
    }

    //recursive call 
    ListNode* recKaAns = NULL;
    if(nextNode != NULL){
        recKaAns = reverseKGroup(nextNode, k);
        head->next = recKaAns;
    }
    return prev;

    }
};
