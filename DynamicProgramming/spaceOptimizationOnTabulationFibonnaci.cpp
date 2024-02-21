int solveUsingTabulationwithSpaceOptimization(int n){
        // step1: create a dp array 
       
        //step2: fill the dp array 
        // dp[0] = 0;
        int prev = 0;
        if(n == 0){
            return 0;
        }
        // dp[1] = 1; 
        int curr = 1;
        if(n == 1){
            return 1;
        }


        //step3: bache hoe dp array ko fill kardo  
        //array size 0 to n hai 
        //0 and 1 index already fill hai ab hmme 2 se n tak jana hai  
        int ans;
        for(int i=2; i<=n; i++){
            // dp[i] = dp[i-1]+dp[i-2];  //space optimization 
            ans = prev + curr;
            prev = curr;
            curr = ans;

        }

        // return dp[n]; 
        return ans;
    }
