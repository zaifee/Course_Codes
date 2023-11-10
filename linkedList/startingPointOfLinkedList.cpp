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
    ListNode *detectCycle(ListNode *head) {
    
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            if (fast == slow) {
                break;
            }
        }
        if(fast == NULL){
            return NULL;
        }

        // Loop se bahar ayye ho to data mil chuka hoga
        slow = head;

        // Slow and fast 1 step move karo tab tak wo meet na kare
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow; // Return the data of the node where the loop is found.
    }
};

   
