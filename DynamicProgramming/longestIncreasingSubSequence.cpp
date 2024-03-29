class Solution {
public:
    int solveUsingPlainRecursion(vector<int>& nums,int curr, int prev){
        
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingPlainRecursion(nums, curr+1, curr);
        }
        int exclude = 0 + solveUsingPlainRecursion(nums, curr+1, prev);

        int ans = max(include, exclude);
        return ans;

    }

     int solveUsingMem(vector<int>& nums,int curr, int prev,          vector<vector<int> >& dp){
        
        if(curr >= nums.size()){
            return 0;
        }
//Indexing
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMem(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMem(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];

    }


    int solveUsingTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr_index = n-1;  curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
            if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                include = 1 + dp[curr_index+1][curr_index+1];
            }
            int exclude = 0 + dp[curr_index+1][prev_index+1];

            dp[curr_index][prev_index+1] = max(include, exclude);
            }
        }
        return dp[0][-1+1]; //doing indexing
    }


    
    int solveUsingTabSO(vector<int>& nums){
        int n = nums.size();
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr_index = n-1;  curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
            if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
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

    int usingBS(vector<int>& nums){
     vector<int>ans;
     ans.push_back(nums[0]);

     for(int i = 1; i < nums.size(); i++){
         if(nums[i] > ans.back()){
             ans.push_back(nums[i]);
         }
         else{
             //findout just bada number 
             int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
             ans[index] = nums[i];
         }
     }
     return ans.size();
        
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        // int ans = solveUsingPlainRecursion(nums, curr, prev); 
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(nums, curr, prev, dp); 
        // int ans = solveUsingTab(nums); 
        // int ans = solveUsingTabSO(nums); 
        int ans = usingBS(nums);
        
        return ans;
    }
};
