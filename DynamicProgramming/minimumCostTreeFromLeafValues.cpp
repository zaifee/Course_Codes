class Solution {
public:
    int solveUsingPlainRec(vector<int>& arr, int s, int e, map< pair<int,int>, int> &maxi){
        if(s > e){
            return 0;
        }
        if(s == e){
            return 0; //for non-leaf sum will be 0;
        }

//Now doing partioning and partioning can be of diff diff types so running loop 
        //i used here for partioning 
        int ans = INT_MAX;
        
        for(int i=s; i < e; i++){
            //product of non-leaf node baki recursion dekh lega 
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1, e}]) + 
                   solveUsingPlainRec(arr, s, i, maxi)+ 
                   solveUsingPlainRec(arr, i+1, e, maxi));
        }
        return ans;
    }
    int solveUsingMem(vector<int>&arr, int s, int e, map< pair<int,int>, int> &maxi, vector<vector<int>> &dp){
         if(s > e){
             return 0;
         }
         if(s == e){
             return 0;
         }

         if(dp[s][e] != -1) return dp[s][e];

         //doing partioning
         int ans = INT_MAX; 
         for(int i = s; i < e; i++){ //i<= e nhi karna tle dega 
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1, e}]) //range maxi se lelo
             + solveUsingMem(arr, s, i, maxi, dp)+
             solveUsingMem(arr, i+1, e, maxi, dp));
         }
         dp[s][e] = ans;
         return dp[s][e];

    }
    
    int solveUsingTab(vector<int>&arr, map< pair<int,int>, int> &maxi){
        //declare the dp vector 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int start_index = n-1; start_index >= 0; start_index--){
            for(int end_index = 0;  end_index < n; end_index++){
                     if(start_index >= end_index){
                           continue;
                     }

                        int ans = INT_MAX; 
                    for(int i = start_index ; i < end_index; i++){ //i<= e nhi karna tle dega 
        ans = min(ans, (maxi[{start_index , i}] * maxi[{i+1, end_index}]) + dp[start_index ][i]+ dp[i+1][end_index]);
                        
                    }
                    dp[start_index ][end_index] = ans;

            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
      int n = arr.size();
      //har range ka maximum calulate kar rahe hai 
       map< pair<int,int>, int> maxi;
       for(int i=0; i<arr.size(); i++){
           maxi[{i, i}] = arr[i];
           for(int j=i+1; j<arr.size(); j++){
               maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]); //yaha galti ki thi
           }
       }   
       //sari ke sare range max element store karwa liye 
       int start = 0;
       int end = n-1;
       
    //    int ans = solveUsingPlainRec(arr, start, end, maxi); 
          vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //   int ans = solveUsingMem(arr, start, end, maxi, dp); 
        int ans = solveUsingTab(arr, maxi);
       return ans;
    }
};
