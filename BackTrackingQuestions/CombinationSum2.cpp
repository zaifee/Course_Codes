class Solution {
public:
 
 void comFinder(vector<int>&candidates, int target, vector<int>&v, vector<vector<int>>&ans,  int index){
     
     if(target == 0){
         ans.push_back(v);
         return;
     }

     if(target < 0 || index == candidates.size()){
         return;
     }

     //picking and droping 
     for(int i=index; i<candidates.size(); i++){
         if(i > index && candidates[i] == candidates[i-1]){
             continue; //skipping duplicates
         }
         v.push_back(candidates[i]);

         //recursive call 
         // yaha sabse badi galti ki index+1 nhi hoga i+1 hoga
         comFinder(candidates, target-candidates[i], v,ans, i+1);
         v.pop_back();
     }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        vector<int>v;
        comFinder(candidates, target, v, ans, 0);
       
        return ans;
    }
};
