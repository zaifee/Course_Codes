//Time Complexity - O(2*n) this is the complexity of two loops inside the sliding window or we can say =O(n);
//O(log n) //this is the complexity of removing or inserting in the heap
//total Time Complexity - O(n * log(n)) 


class Solution {
public:
    typedef pair<int , int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        priority_queue<P> maxHeap;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        // Space Complexity - O(n, n) = O(2*n)

        int i = 0;
        int j = 0;
        int maxLength = 0;

        while(j < n){

            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});

            //Now update i means increment i; i will increment when nums[j]-nums[i] > limit
            //to update i we will select first minimum value from any one of the heap


            while(maxHeap.top().first - minHeap.top().first > limit){
                //increment i selecting minimum value of index

                i = min(maxHeap.top().second, minHeap.top().second) + 1;
                //after selecting value we are incrementing it +1;

                //Now delete the value which are less than ith index;

                while(maxHeap.top().second < i){
                    maxHeap.pop();
                }

                while(minHeap.top().second < i){
                    minHeap.pop();
                }

            }

                maxLength = max(maxLength, j-i+1);
                j++;
        }

                return maxLength;
        
    }
};
