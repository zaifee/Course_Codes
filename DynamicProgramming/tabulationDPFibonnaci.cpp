
    int solveUsingTabulation(int n){
        // step1: create a dp array 
        vector<int>dp(n+1, -1);

        //step2: fill the dp array 
        dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;

        //step3: bache hoe dp array ko fill kardo  
        //array size 0 to n hai 
        //0 and 1 index already fill hai ab hmme 2 se n tak jana hai  
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }

 int fib(n){
   return solveUsingTabulation( n );
 }
