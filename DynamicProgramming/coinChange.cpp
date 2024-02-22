
class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount){
        //base case 
         if(amount == 0){
             return 0;
         }

         int mini = INT_MAX;
        //processing 
        for(int i=0; i<coins.size(); i++){
             int coin = coins[i];
// valid case 
             if(amount - coin >= 0){
                 int recursionKaAns = solveUsingRecursion(coins, amount-coin);
                 if( recursionKaAns != INT_MAX){
                     //ek coin use ho gya baki tum nikal ke le aao  
                    int ans = 1 + recursionKaAns;
                     mini = min(ans, mini);
                 }
             }
        }


        return mini;
    }

 // Using Memoization 
   int solveUsingMem(vector<int>& coins, int amount, vector<int>&dp){
       //base case 
         if(amount == 0){
             return 0;
         }
         if(dp[amount] != -1){
             return dp[amount];
         }
         
         int mini = INT_MAX;
        //processing 
        for(int i=0; i<coins.size(); i++){
             int coin = coins[i];
// valid case 
             if(amount - coin >= 0){
                 int recursionKaAns = solveUsingMem(coins, amount-coin,dp);
                 if( recursionKaAns != INT_MAX){
                     //ek coin use ho gya baki tum nikal ke le aao  
                    int ans = 1 + recursionKaAns;
                     mini = min(ans, mini);
                 }
             }
        }
    //step2: store in dp array 
      dp[amount] = mini;
        return dp[amount];
   }








    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        // int ans = solveUsingRecursion(coins, amount);  
        // create a dp array 
        vector<int>dp(n+1, -1);

        int ans = solveUsingMem(coins,amount, dp);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
        return ans;
    }
};
