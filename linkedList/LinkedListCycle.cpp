/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
     ListNode* fast = head;
     ListNode* slow = head;
     while(fast != NULL){
         fast = fast->next;
         if(fast != NULL){
             fast = fast->next;
             slow = slow->next;
         }
         //agar loop hai slow and fast equal ho gye honge
         if(fast == slow){
             return true;
         }
     }
     return false;










        //Using map data sturcture 
    // create a mapping address or uska status rakhna hai 
    // map<ListNode*, bool>table;

    // ListNode* temp = head;
    // while(temp != NULL){
    //     if(table[temp] == false){
    //         table[temp] = true;
    //     }
    //     else{
    //         //cycle absent 
    //        return true;
    //     }
    //     temp = temp->next;
    // }
    // return false;

    }
};
