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
ListNode* reverseList(ListNode* prev, ListNode* curr) {
        //base case 
     if(curr == NULL){
         return prev;
     }
     //1 case solve karlo 
     ListNode* nextNode = curr->next;
     curr->next = prev;
     prev = curr;
     curr = nextNode;

    //  ListNode* recursionkaAns = reverseList(prev, curr);
    //   return recursionkaAns;
     
     return reverseList(prev, curr);
       
 
}
bool compareList(ListNode* head, ListNode* head2){
    ListNode* temp = head;
    ListNode* tempi = head2;
   while(head2 != NULL){
       if(head -> val != head2->val){
           return false;
       }
       else{
        //    temp = temp->next; 
         head = head->next;
          head2 = head2->next;
        //    tempi = tempi->next;
       }
   }
   return true;


}

    ListNode* middleNode(ListNode* head) {
       
      
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast->next != NULL){  //yaha galti ki thi
           fast = fast->next; //pehle ek hi step chal ke dekh lo aage node bhi ya nhi
           if(fast->next != NULL){ //yaha galti ki thi
               //me yaha keh sakta hu fast ne du steps chal liye honge 
               fast = fast->next;
               slow = slow->next;
           }
       }
       return slow;
    }


    bool isPalindrome(ListNode* head) {

       ListNode* midNode = middleNode(head);
       //dusri linked list ka head2 nikal liya line 32 se 
    //    break it into two halves
       ListNode* head2 = midNode->next;
       midNode->next = NULL;

//    reverse of linked list 2 ka
       ListNode* prev = NULL;
       ListNode* curr = head2;
       head2 = reverseList(prev, curr);

       //compare two list 
       bool ans = compareList(head, head2);

       return ans;


 
    }
};
