class Solution {
public:
    int solveUsingPlainRecursion(int start, int end){
        if(start >= end){
            return 0; //penalty 0 deni hogi 

        }

        int ans = INT_MAX; //as we have to find the Minimum ans 
        for(int i=start;  i <= end; i++){
            ans = min(ans, i+ max(solveUsingPlainRecursion(start, i-1),
            solveUsingPlainRecursion(i+1, end)));
        }

        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int>> &dp){
          if(start >= end){
            return 0; //penalty 0 deni hogi 

        }
         if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX; //as we have to find the Minimum ans 
        for(int i=start;  i <= end; i++){
            ans = min(ans, i+ max(solveUsingMem(start, i-1, dp),
            solveUsingMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveUsingBottomUp(int n){
         vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
         
         for(int start_index = n; start_index >= 1; start_index--){
             for(int end_index = 1; end_index <= n; end_index++){

                 if(start_index >= end_index){
                     continue; //invalid range
                 }
            int ans = INT_MAX; //as we have to find the Minimum ans 
            for(int i=start_index;  i <= end_index; i++){
                ans = min(ans, i + max(dp[start_index][i-1],
                dp[i+1][end_index]));
            }
              dp[start_index][end_index] = ans;

             }
         }
         return dp[1][n];
    }


    // int solveUsingTabSO(int n){
    //     //not poss
    // }

    int getMoneyAmount(int n) {
      //merge wala pattern 
      int start = 1;
      int end = n;
    //   int ans = solveUsingPlainRecursion(start, end);  
     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //  int ans = solveUsingMem(start, end ,dp); 
       int ans = solveUsingBottomUp(n);
      return ans;
    }
};
