class Solution {
public:
    int solveUsingPlainRec(string &a, string &b, int i, int j){

        if(i == a.length()){
            return b.length()-j;
        }

        if(j == b.length()) return a.length()-i; //bache hoi string ke char return kar rahe
        int ans = 0;
        if(a[i] == b[j]){
           ans = 0 + solveUsingPlainRec(a, b, i+1, j+1); //yaha galti ki thi
        }
        else{
          //replacement wale case replacement, insertion, deletion 
           int replace = 1 + solveUsingPlainRec(a, b, i, j+1);

           int insert = 1 + solveUsingPlainRec(a, b, i+1, j);

           int deletion = 1 + solveUsingPlainRec(a, b, i+1, j+1);

           ans = min(replace, min(insert, deletion));





        }
        return ans;
    }

   int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){

        if(i == a.length()){
            return b.length()-j;
        }

        if(j == b.length()) return a.length()-i; //bache hoi string ke char return kar rahe

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
           ans = 0 + solveUsingMem(a, b, i+1, j+1, dp); //yaha galti ki thi
        }
        else{
          //replacement wale case replacement, insertion, deletion 
           int replace = 1 + solveUsingMem(a, b, i, j+1, dp);

           int insert = 1 + solveUsingMem(a, b, i+1, j, dp);

           int deletion = 1 + solveUsingMem(a, b, i+1, j+1, dp);

           ans = min(replace, min(insert, deletion));
   
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

  
   int solveUsingTabulation(string &a, string &b){
       vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));

       for(int col=0; col <= b.length(); col++){
           dp[a.length()][col] = b.length()-col;
       }
       for(int row=0; row <= a.length(); row++){
           dp[row][b.length()] = a.length()-row;
       }
     
      for(int i_index = a.length()-1;  i_index >= 0;  i_index--){
          //we are going bottom to up in dp so we are going from n-1
          for(int j_index = b.length()-1; j_index >= 0;  j_index--){
            int ans = 0;

         if(a[i_index] == b[j_index]){
           ans = 0 + dp[i_index+1][j_index+1]; //yaha galti ki thi
        }
        else{
          //replacement wale case replacement, insertion, deletion 
           int replace = 1 + dp[i_index+1][j_index+1];

           int insert = 1 + dp[i_index][j_index+1];

           int deletion = 1 + dp[i_index+1][j_index];

           ans = min(replace, min(insert, deletion));
   
        }
        dp[i_index][j_index] = ans;
        }

      }
      return dp[0][0];

   }

  int solveUsingTabulationSO(string &a, string &b){
    //    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1)); 
     vector<int> curr(a.length()+1, 0);
     vector<int> next(a.length()+1, 0);

    //    for(int col=0; col <= b.length(); col++){
    //        dp[a.length()][col] = b.length()-col;
    //    } abhi ke liye bhul jao -- iska khuch na khuch to karna padega nhi to galti kar denge 

       for(int row=0; row <= a.length(); row++){
           next[row] = a.length()-row;
       }
//chang isliye kiya taki traversal column wise ho     
       for(int j_index = b.length()-1; j_index >= 0;  j_index--){
           //hr new curr column ke last wale dabbe ans insert karo 
           //Most Important point
           curr[a.length()] = b.length()-j_index;
      for(int i_index = a.length()-1;  i_index >= 0;  i_index--){
          //we are going bottom to up in dp so we are going from n-1
        
            int ans = 0;

         if(a[i_index] == b[j_index]){
           ans = 0 + next[i_index+1]; //yaha galti ki thi
        }
        else{
          //replacement wale case replacement, insertion, deletion 
           int replace = 1 + next[i_index+1];

           int insert = 1 + next[i_index];

           int deletion = 1 + curr[i_index+1];

           ans = min(replace, min(insert, deletion));
   
        }
        curr[i_index] = ans;
        }
        //shifting yaad ni rehti 
        next = curr;

      }
      return next[0];

   }







    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // int ans = solveUsingPlainRec(word1, word2, i, j);  
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // int ans = solveUsingMem(word1, word2, i, j, dp); 
        // int ans = solveUsingTabulation(word1, word2);  

        int ans = solveUsingTabulationSO(word1, word2);
        return ans;
    }
};
