class Solution {
public:
    int solveUsingPlainRecursion(vector<int>&nums, int size, int index){
      
     //base case 
     if(index >= size){
         return 0;
     }
     int robbedfirstHouse = nums[index]+solveUsingPlainRecursion(nums, size, index+2);
     int notRobbedfirstHouse = 0 + solveUsingPlainRecursion(nums, size, index+1);

      int ans = max(robbedfirstHouse, notRobbedfirstHouse);
      return ans;


    }

    int solvingUsingMem(vector<int>&dp,  vector<int>&nums, int index){
      
      if(index >= nums.size()) return 0;

      //step2: if ans already exist return that ans
      if(dp[index] != -1){
          return dp[index];
      }

      
      int include = nums[index]+ solvingUsingMem(dp, nums, index+2);
      int exclude = 0 + solvingUsingMem(dp, nums, index+1);

    //step2: Store in the Dp Array
      dp[index]= max(include, exclude);
      return dp[index];


    }
    int rob(vector<int>& nums) {
        int index = 0;
       int n = nums.size();
    
    //   return solveUsingPlainRecursion(nums, n, index);
      //    creating a one-d dp array becz only index is changing 
       vector<int>dp(n+1, -1); 
       return solvingUsingMem(dp, nums, index);

    }
};
