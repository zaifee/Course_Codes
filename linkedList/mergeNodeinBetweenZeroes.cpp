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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode* slow = head, *fast = head->next, * newLastNode = 0;
        int sum = 0; 
        while(fast){
            if(fast->val != 0){
                sum += fast->val;
                
            }
            else{
                //fast->val != 0
                slow->val = sum; //starting pe sum set kar di
                newLastNode = slow; //newLastNode ko slow pe point kara do
                slow = slow->next;
                sum = 0;  //sum ko reset kar diya 

            }
            //fast ko move kardo 
            fast = fast->next;
    
          } 

           ListNode* temp = newLastNode->next;
            newLastNode->next = NULL;  

   
            //temp wo node hai jo delete karna hai 
            while(temp){
     //nxt pointer isliye liya taki next pointer hmm ra temp ke aage point kare
     //or hmm temp wali node delete kar pai 
                ListNode* nxt = temp->next; 
                
                delete temp;
                temp = nxt;
            }
        // delete temp;
      
        
       
        return head;
    }
};
