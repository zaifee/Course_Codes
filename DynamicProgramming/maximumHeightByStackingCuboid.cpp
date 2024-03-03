class Solution {
public:
   bool checkCuboidDimension(vector<int>& curr, vector<int>& prev){
       //yaha galti ki thi 
       
       if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
           return true;
       }
       else{
           return false;
       }
   }
    int solveUsingTabSO(vector<vector<int>>& cuboids){
        int n = cuboids.size();
      
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr_index = n-1;  curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
            if(prev_index == -1 || checkCuboidDimension(cuboids[curr_index], cuboids[prev_index])){
                int heightToAdd = cuboids[curr_index][2]; //max hegi of cuboid
                include = heightToAdd + nextRow[curr_index+1];
            }
            int exclude = 0 + nextRow[prev_index+1];

             currRow[prev_index+1] = max(include, exclude);
            }
            //shifting 
            nextRow = currRow; //ye bhul jate hai
        }
        return  nextRow[-1+1]; //doi
        
        

    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabSO(cuboids);
        return ans;

    }
};
