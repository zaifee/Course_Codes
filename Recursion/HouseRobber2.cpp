class Solution {
public:
int solve(vector<int>&nums, int s, int e){
//base case 
if(s > e) return 0;

int robbedFirstPosition = nums[s] + solve(nums, s+2, e);

int notRobbedPosition = 0 + solve(nums, s+1, e);

int finalAns = max(robbedFirstPosition, notRobbedPosition);

return finalAns;



}
    int rob(vector<int>& nums) {
        int n = nums.size();
        //Using house robber_1 wala code 
       if(nums.size() == 1){
           return nums[0];
       }

     int option1 = solve(nums, 0, n-2); //last wala robbed nhi kar sakte bcz of circular pos
     int option2 = solve(nums, 1, n-1); //first house robbed nhi kiya 
     
     int ans = max(option1, option2);
     return ans;

       

    }
};
