class Solution {
public:
  int solve(vector<int>& nums, int size, int index){
      //base case 
    
    if(index >= size) return 0;

    int robbedFirstHouse = nums[index]+solve(nums, size, index+2);

    int notRobbedFirstHouse = 0 + solve(nums,size, index+1);

    int finalAns = max(robbedFirstHouse, notRobbedFirstHouse);

    return finalAns;

  }
    int rob(vector<int>& nums) {
        
     int size = nums.size();
     int index = 0;

   int ans =  solve(nums, size, index);

   return ans;

   





    }
};
