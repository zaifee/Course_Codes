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
  ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
      if(!l1) return l2;
      if(!l2) return l1;

      if(l1->val <= l2->val){
          l1->next = mergeTwoList(l1->next, l2);
          return l1;
      }
      else{
          l2->next = mergeTwoList(l1, l2->next);
          return l2;
      }
      return l1;
  }

   ListNode* mergeAndPartition(int s, int e, vector<ListNode*>lists){
       if(s == e) return lists[s];
       if(s > e) return NULL;
        
      int mid =  s + (e-s)/2;
       ListNode* l1 = mergeAndPartition(s, mid, lists);
       ListNode* l2 = mergeAndPartition(mid+1, e, lists);

       return mergeTwoList(l1, l2);
   }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
       
       return mergeAndPartition(0, n-1, lists);
    }
};
