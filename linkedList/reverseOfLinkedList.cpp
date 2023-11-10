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
  ListNode* ReverseUsingRecursion(ListNode* prev, ListNode* curr){
     //base case 
     if(curr == NULL){
         return prev;
     }
     //1 case solve karlo 
     ListNode* nextNode = curr->next;
     curr->next = prev;
     prev = curr;
     curr = nextNode;

     ListNode* recursionkaAns = ReverseUsingRecursion(prev, curr);
      return recursionkaAns;
  }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        // while(curr != NULL){
        //     ListNode* nextNode = curr->next; //track rakhna ke liye kiya 
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // head = prev; //yaha galti karoge head return karna hai to prev return kardo
        // return head;

        //recursion 
        return ReverseUsingRecursion(prev, curr);
    }
};
