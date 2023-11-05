class Solution {
public:
void countArrangementFinder(vector<int>&v, int&n, int &ans, int currNum){
  //base case 
  if(currNum == n+1){
    ++ans;
    return;
  }


  for(int i=1; i<=n; i++){
    if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
       v[i] = currNum;
       countArrangementFinder(v, n, ans, currNum+1);
       v[i] = 0; //backtrack kar rahe hai //
    }
  }
}
    int countArrangement(int n) {
        vector<int>v(n+1); //ye v(n+1) ka size nhi liya tha
        int ans = 0;
        countArrangementFinder(v, n, ans, 1);  //1 means index;
        return ans;
    }
};
