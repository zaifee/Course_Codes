class Solution {
public:
  void permutationHelper(vector<int>&nums, vector<vector<int>>&ans, int start){
    //base case 
    if(start == nums.size()){
        ans.push_back(nums);
        return;
    }
    unordered_map<int,bool>visited;

   for(int i=start; i<nums.size(); i++){
     if(visited.find(nums[i]) != visited.end()){
             continue;  //help to remove duplicates 
     }
      visited[nums[i]] = true;
       swap(nums[i], nums[start]);
      permutationHelper(nums, ans, start+1);
      swap(nums[i], nums[start]);

   }

  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permutationHelper(nums, ans, 0);
        set<vector<int>>st;
        // for(auto e: ans){
        //   st.insert(e);
        // }
        // ans.clear();

        // for(auto e: st){
        //   ans.push_back(e);
        // }
        return ans;
    }
};
