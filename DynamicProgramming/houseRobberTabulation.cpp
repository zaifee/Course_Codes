int solveUsingTabulation(vector<int>&nums){
      int n = nums.size();
      //step1: create a dp array 
      vector<int>dp(n, -1);

      //step2: fill the dp array with the base case knowledge

//yaha hmme sochna padega bcz initial state me invalid index hai to zero return kar rahe hai but invalid index dp me hai hi nhi to zero nhi dal sakte. It means mere pass koi initial state hi nhi hai so additional soch rhe hai to wo konsa answer hai jo me manually fill kar sakta ho -- last wala fill kar sakte hai
      dp[n-1] = nums[n-1]; //last wali amount dp array me aagyi 

      for(int index = n-2; index >= 0; index--){
          int tempAns = 0;
          if(index+2 < n){
              tempAns = dp[index+2]; 
              //n-2 me n-2+2 kardo ge ye case phat jai ga bcz n exist hi nhi karta 
          }

          int include = nums[index] + tempAns;
          int exclude = 0 + dp[index+1];

          dp[index]= max(include, exclude);
      }
//99% case me jo initial state bheji hai wo return karna hota hai 
      return dp[0]; //hmm right se left ki taraf aa rahe hamra ans to left ki taraf build hoga 
   }
