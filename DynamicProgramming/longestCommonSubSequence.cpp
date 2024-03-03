class Solution {
public:
    int solveUsingPlainRec(string str1, string str2, int i, int j){
      
      //base case 
      if(i >= str1.length()){
          return 0;
      }
      if(j >= str2.length()){
          return 0;
      }
      
      int ans = 0;
      if(str1[i] == str2[j]){
          ans = 1 + solveUsingPlainRec(str1, str2, i+1, j+1);
      }
      else{
          //i ko ignore kar diya aur j ko increment kar diya while dursre case i ko increment kar diya j ko const rakha 
          ans = 0 + max(solveUsingPlainRec(str1, str2, i, j+1), solveUsingPlainRec(str1, str2, i+1, j));
      }

      return ans;


    }


    int solveUsingMemoization(string& str1, string& str2, int i, int j, vector<vector<int>> &dp){
      
      //base case 
      if(i >= str1.length()){
          return 0;
      }
      if(j >= str2.length()){
          return 0;
      }

      //if already stored return it 
      if(dp[i][j] != -1){
          return  dp[i][j];
      }
      
      int ans = 0;
      if(str1[i] == str2[j]){
          ans = 1 + solveUsingMemoization(str1, str2, i+1, j+1, dp);
      }
      else{
          //i ko ignore kar diya aur j ko increment kar diya while dursre case i ko increment kar diya j ko const rakha 
          ans = 0 + max(solveUsingMemoization(str1, str2, i, j+1,dp), solveUsingMemoization(str1, str2, i+1, j, dp));
      }
      dp[i][j] = ans; 
      return dp[i][j];
    }



     int solveUsingTabulation(string& str1, string& str2){
      vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, 0));
      //base case ho gya by marking every element zero 
      
       for(int i_index = str1.length()-1; i_index >= 0;  i_index--){
           for(int j_index = str2.length()-1;  j_index >= 0;  j_index--){
                 int ans = 0;
             if(str1[i_index] == str2[j_index]){
            ans = 1 + dp[i_index+1][j_index+1];
           }
          else{
         
           ans = 0 + max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
          }

          dp[i_index][j_index] = ans; 
        }
        
    }
      
     
      
      return dp[0][0];
    }



    int solveUsingTabulationSO(string& str1, string& str2){
    //   vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, 0));
      //base case ho gya by marking every element zero 
        vector<int>curr(str1.length()+1, 0);
        vector<int>next (str1.length()+1, 0);

        int ans = 0;
        for(int j_index = str2.length()-1;  j_index >= 0;  j_index--){
                
       for(int i_index = str1.length()-1; i_index >= 0;  i_index--){
        
             if(str1[i_index] == str2[j_index]){
            ans = 1 + next[i_index+1];
           }
          else{
         
           ans = 0 + max(next[i_index], curr[i_index+1]);
          }

          curr[i_index] = ans; 
        }
        //shifting 
        next = curr;
        
    }
      
     
      return next[0];
    }
     
 

    int solveUsingTabulationNOLoopChange(string& str1, string& str2){

      //base case ho gya by marking every element zero 
      vector<int> currRow(str2.length()+1, 0);
      vector<int> nextRow(str2.length()+1, 0);

      
       for(int i_index = str1.length()-1; i_index >= 0;  i_index--){
           for(int j_index = str2.length()-1;  j_index >= 0;  j_index--){
                 int ans = 0;
             if(str1[i_index] == str2[j_index]){
              ans = 1 +  nextRow[j_index+1];
           }
          else{
         
           ans = 0 + max(currRow[j_index+1],  nextRow[j_index]);
          }

          currRow[j_index] = ans; 
        }
        //shiftingn 
        nextRow = currRow;
        
    }
      
     
      
      return nextRow[0];
    }


    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // int ans = solveUsingPlainRec(text1, text2, i, j);  
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        //0 se length tak ja rha o isliye +1 kara 

        // auto ans = solveUsingMemoization(text1, text2, i, j, dp); 
        //  int ans = solveUsingTabulation(text1, text2); 
        //  int ans = solveUsingTabulationSO(text1, text2);
           int ans = solveUsingTabulationNOLoopChange(text1, text2);
        return ans;
    }
};
