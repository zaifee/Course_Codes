#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k){
  if(n == 1){
    return k;
  }
  if(n == 2){
    return (k + k * (k-1));
  }
   
  int ans = (solveUsingRecursion(n-1, k)+solveUsingRecursion(n-2, k))*(k-1);
  return ans;

}


int solveUsingMem(int n, int k, vector<int>&dp){
    if(n == 1) return k;
    if(n == 2) return k + k*(k-1);
    
    //step3: if ans already exist return that dp array 
    if(dp[n] != -1){
        return dp[n];
    }
    
    dp[n] = (solveUsingMem(n-1, k, dp)+solveUsingMem(n-2, k, dp))*(k-1);
  return dp[n];
}

int solveUsingTabulation(int n, int k){
    //create a dp array 
    vector<int>dp(n+1, -1);
    
    dp[1]= k;
    dp[2] = k + k*(k-1);
    
    //loop ka use karlo 2 se n tak 
    for(int val = 3; val <= n; val++){
        dp[val] = (dp[val-1]+ dp[val-2])*(k-1);
    }
    return dp[n];
    
}

int solveUsingTabulationSO(int n, int k){
    //create a dp array 
    // vector<int>dp(n+1, -1);
    
    // dp[1]= k;
    // dp[2] = k + k*(k-1); 
    
    
    
    int prev1 = k-1;
    int prev2 = k+ k*(k-1);
    int curr;
    
    if(n == 1){
        return prev;
    }
    if(n == 2){
        return curr;
    }
    
    //loop ka use karlo 2 se n tak 
    for(int val = 3; val <= n; val++){
        curr =  (prev1 + prev2) * (k-1);
    }
    return curr;
    
}




int main() {
  int n = 3;
  int k = 2;

//   int ans = solveUsingRecursion(n, k); 
 vector<int>dp(n+1, -1);
//   int ans = solveUsingMem(n, k, dp); 
//  int ans = solveUsingTabulation(n, k); 
int ans = solveUsingTabulationSO(n, k);
   
 cout << "Ans : " << ans << endl;


  return 0;
}
