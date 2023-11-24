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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        //pusing in ll
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }

        // vector<int>ans(ll.size());
        stack<int>st;
        for(int i=0; i<ll.size(); i++){
             while(!st.empty() && ll[i] > ll[st.top()]){
            //ith element will be the next greater element
            int kids = st.top();
            st.pop();
            ll[kids] = ll[i];
        }
        st.push(i);
        }
    //another edge case handling -- jin jin ka next element nhi mila hoga wo stack me hi honge  
    while(!st.empty()){
      ll[st.top()] = 0;
      st.pop(); //pop isliye  kara hamm wo return karna hai
    }

        ll[ll.size()-1] = 0; //putting zero at last 
       return ll;
    }
};
