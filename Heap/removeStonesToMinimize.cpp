class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxHeap;
        for(int i=0; i<piles.size(); i++){
            maxHeap.push(piles[i]); //maxheap create kar liya 
        }

        while(k--){
            int topElement = maxHeap.top();
            maxHeap.pop();
        //   processing 
            topElement = topElement - floor(topElement/2);
            // updation of element after subtracting from it;
            maxHeap.push(topElement);
        }
        int sum = 0;
        while(!maxHeap.empty()){
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }

        return sum;
    }
};
