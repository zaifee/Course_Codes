class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;

        int s = 0;
        int e = n-1;
        while(s <= e){
         int mid = s + (e-s)/2;
        //  we have a formula for searching in matrix but in 2d
        int rowIndex = mid/col;
        int colIndex = mid % col;
        
        int currNumber = matrix[rowIndex][colIndex];

        if(currNumber == target){
            return true;
        }else if(target > currNumber){
            s = mid + 1;
        }else{
            e = mid - 1;
        }

        }
        return false;
    }
};
