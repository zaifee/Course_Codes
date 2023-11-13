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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //empty list 
        if(head == NULL) return 0;
        int len = getLength(head);

        int actualRotate = (k % len);

        if(actualRotate == 0){
            return head;
        }
        int newLastNodePost = len-actualRotate-1;
        ListNode* newLastNode = head;
        //newLastNode tak pohuchna hai newLastNodePost ki help se 
        for(int i=0; i<newLastNodePost; ++i){
            newLastNode = newLastNode->next;
        }
//ab waha pohuch gye honge newHead mil jai ga to use newLastNode ke next par point kara do
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL; //ise null point kara diya

        //ab hmm newHead ko starting head par set karna hai 
        ListNode* it = newHead;
        while(it->next != NULL){
            it = it->next;
        }
        //ab hmm last se pehli locn par point khade honge yani tail pe 
        //to use original head par point kara do 
        it->next = head;

        return newHead;
        

    }
};
