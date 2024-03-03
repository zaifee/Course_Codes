class Solution {
public:
   bool check(vector<int>& curr, vector<int>& prev){
       if(curr[0] > prev[0] && curr[1] > prev[1]){
           return true;
       }
       else{
           return false;
       }
   }
    int solveUsingTab(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr_index = n-1;  curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
            if(prev_index == -1 || check(envelopes[curr_index],envelopes[prev_index])){
                include = 1 + nextRow[curr_index+1];
            }
            int exclude = 0 + nextRow[prev_index+1];

             currRow[prev_index+1] = max(include, exclude);
            }
            //shifting 
            nextRow = currRow; //ye bhul jate hai
        }
        return  nextRow[-1+1]; //doing indexing


    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int ans = solveUsingTab(envelopes);
        return ans;
    }
};
