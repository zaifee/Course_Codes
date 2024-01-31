class Info{
public:
int data;
int rowIndex;
int colIndex;

Info(int value, int rowValue, int colValue):data(value), rowIndex(rowValue), colIndex(colValue){};

};
class compare{
public:
bool operator()(Info* element1, Info* element2){
    return element1->data > element2->data;
}
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
         int maxi = INT_MIN;
         int mini = INT_MAX;
        // process first k elements ka min nikal liya or max nikal liya
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            int row = i;
            int col = 0;

            Info *temp = new Info(element, row, col);
            pq.push(temp); //pushing data into the heap
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        int ansStart = mini; //ya first k elements ki range aayi 
        int ansEnd = maxi;
//ab baki jo list ke elements hai unke liye process karenge 
        while(!pq.empty()){
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topCol = topNode->colIndex;
            int topRow = topNode->rowIndex;
            pq.pop();

            //yani ek new range hamare pass bani hogi 
            mini = topNode->data;
            //maxi value pehle se hi padi hai 
            //to ab compare kar lete hai
            if((maxi-mini) < (ansEnd-ansStart)){
                //update the ans
                
                 ansStart = mini;
                 ansEnd = maxi;
            } 

            //insertion wala step 
            if(topCol+1 < nums[topRow].size()){
                //insert karo to max update karna hota hai 
                int newElement = nums[topRow][topCol+1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo); //ye bhul gya tha
            }
            else{
                break;
            }

        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};
