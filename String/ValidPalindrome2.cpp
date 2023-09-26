class Solution {
public:
// I have solved this question using two pointers approach in which i and j are two 
// pointer which is started from 0th index or lastindex
  bool checkPalindrome(string s, int i, int j){
      while(i <= j){
          if(s[i] != s[j]){
              return false;
          }else{
              i++;
              j--;
          }
      } //yaha tak aaye ho to palindrome hi hoge  
      return true;
  }
    bool validPalindrome(string s) {
     //solving using two pointers approach 
     int i = 0;
     int j = s.length()-1;
     while(i <= j){
       //if char are same 
       if(s[i] == s[j]){
           i++;
           j--;
       }else{
       //if chars are diff so removing char and checking palindrome 
       bool leftSide = checkPalindrome(s, i+1, j);
       bool rightSide = checkPalindrome(s, i, j-1);
        return leftSide || rightSide;
     }
    }
      //yaha tak aaye ho to palindrome pakka hoge 
      return true;
    }
};
