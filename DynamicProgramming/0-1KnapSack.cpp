class Solution
{
    public:
    int usingPlainRecursion(int W, int wt[], int profit[], int n, int index){
        
        //base case 
        if(index == n-1){
            
            if(wt[index] <= W){
                return profit[index];
            }
            else{
                return 0;
            }
        }
        
        
        
        int include = 0;
  
        if(wt[index] <= W){
            include = profit[index] + usingPlainRecursion(W-wt[index], wt, profit, n, index+1);
        }
        
       int exclude = 0 + usingPlainRecursion(W, wt, profit, n, index+1);
        
        int ans = max(include, exclude);
        
        return ans;
    }
    
int solveUsingTabulation(int W, int wt[], int profit[], int n){
        
        //create a dp array 
        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        
        
        //analyse the base case 
        //Mark zero with coln 
        for(int row = 0; row <= W; row++){
            dp[row][n] = 0;
        }
        
//capacity negative ki taraf ja rhi or hmm top down approach use kar rhe hai to n tak jai ge le tak 
        for(int i=0; i <= W; i++){
            for(int j=n-1; j >= 0; j--){
                 
            int include = 0;
  
             if(wt[j] <= i){
            include = profit[j] + dp[i-wt[j]][j+1];
        }
        
        int exclude = 0 + dp[i][j+1];
        
        //step2: store in the dp Array
        dp[i][j] = max(include, exclude);
        
        }
        
    }
       
        
        return dp[W][0];
    }
    
    int solveUsingMemoization(int W, int wt[], int profit[], int n, int index, vector<vector<int>> &dp){
        //base case 
        if(index == n-1){
            
            if(wt[index] <= W){
                return profit[index];
            }
            else{
                return 0;
            }
        }
        
        
        
        //step3: 
        if(dp[W][index] != -1) return dp[W][index];
        
        
        int include = 0;
  
        if(wt[index] <= W){
            include = profit[index] + solveUsingMemoization(W-wt[index], wt, profit, n, index+1, dp);
        }
        
       int exclude = 0 + solveUsingMemoization(W, wt, profit, n, index+1, dp);
        
        //step2: store in the dp Array
        dp[W][index] = max(include, exclude);
        
        return dp[W][index];
    }
    
   
    
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int index = 0;
    //   return  usingPlainRecursion(W, wt, val, n, index); 
        //  vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        
         
        //  return solveUsingMemoization(W, wt, val, n, index, dp);
        return solveUsingTabulation(W, wt, val, n);
    }
};
