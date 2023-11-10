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
 
   int findLength(ListNode* head){
       ListNode* temp = head;
       int cnt = 0;
       while(temp != NULL){
           cnt++;
           temp = temp->next;
       }
       return cnt;
   }
    ListNode* middleNode(ListNode* head) {
        int n = findLength(head);
      
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast != NULL){
           fast = fast->next; //pehle ek hi step chal ke dekh lo aage node bhi ya nhi
           if(fast != NULL){
               //me yaha keh sakta hu fast ne du steps chal liye honge 
               fast = fast->next;
               slow = slow->next;
           }
       }
       return slow;




    //     int pos = n/2+1;
        
    //    ListNode* temp = head;
    //     while(pos != 1){
    //         temp = temp->next;
    //         pos--; //ue bhul gya tha
    //     }
    //     return temp;
        
    
    }
};
