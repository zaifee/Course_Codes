class Solution {
public:
  void combinationFinder(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&vec, int index){

      //base case 
      if(target ==  0){
          ans.push_back(vec);
          return;
      }

      if(target < 0){
          return;
      }

      //find all candidatin by picking and droping 
      for(int i = index; i < candidates.size(); i++){
          vec.push_back(candidates[i]);
          //recursive call 
          combinationFinder(candidates, target-candidates[i], ans, vec, index);
          vec.pop_back();
      }

  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>vec;
        int index = 0;
        combinationFinder(candidates, target, ans, vec, index);
        return ans;
    }
};
