#include<iostream>
using namespace std;
int countWays(int n, int k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return  k+ k *(k-1); // yaha galti ki
        
    }
    
    int ans = (k-1)*(countWays(n-1, k)+countWays(n-2, k));
    return ans;
}
int main(){
    
    int n = 3;
    int k = 3;
  cout <<  countWays(n, k) << endl;
    
    
    
    return 0;
}
