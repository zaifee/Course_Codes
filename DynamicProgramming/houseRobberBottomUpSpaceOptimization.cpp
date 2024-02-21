
   int solveUsingTabulationSpaceOpti(vector<int>&nums){
      int n = nums.size();
      //step1: create a dp array 
    //   vector<int>dp(n, -1);

       int prev = nums[n-1];
       int next = 0; //imaginary hai to 0 zero assume kar liya 
       int curr; 

    //   dp[n-1] = nums[n-1]; //last wali amount dp array me aagyi 

      for(int index = n-2; index >= 0; index--){
          int tempAns = 0;
          if(index+2 < n){
              tempAns = next; 
              //n-2 me n-2+2 kardo ge ye case phat jai ga bcz n exist hi nhi karta 
          }

          int include = nums[index] + tempAns;
          int exclude = 0 + prev;

          curr = max(include, exclude);

        //jo hamesha hmm bhul jate hai 
        next = prev;
        prev = curr;




      }
//99% case me jo initial state bheji hai wo return karna hota hai 
      return curr; //hmm right se left ki taraf aa rahe hamra ans to left ki taraf build hoga 
      //Note:return curr kiya to single case ke liye code phate ga like for 1 it will not go inside the loop so that's why we are returning the prev;
   }
