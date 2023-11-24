//Brute force  approach: 
//User function template for C++

class Solution 
{
    public:
    bool isCelebrity(vector<vector<int> >&M, int person, int n){
        for(int i = 0; i<n; i++){
    //check if you know someone or someone does not you
    if(i != person && (M[person][i] == 1 || M[i][person] == 0)){
             return false;
         }
        }
        return true;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
          for(int i=0; i<n; i++){
             if(isCelebrity(M, i, n)){
                 return i; //i will be the potential candidate
             }
          } 
          
          return -1; //not celebrity is found
    }
};

//optimised approach: 
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>s;
       for(int i=0; i<n; i++){
           s.push(i);
       }
       
       //discard method 
       while(s.size() != 1){
           int a = s.top(); s.pop();
           int b = s.top(); s.pop();
           
           if(M[a][b]){
               //a knows b so it cannot be a celebrity 
               //pusing b
               s.push(b);
           }else{
               //b is not a celebrity 
               s.push(a);
           }
       }
       
       //check that single person which might be a celebrity 
       int mightBeCelebrity = s.top();
       s.pop();
       
       for(int i=0; i<n; i++){
           if(M[mightBeCelebrity][i] != 0){
               return -1;
           }
       }
//cond2 check all col should be except diagonal 
       
    for(int i=0; i<n; i++){
          if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){
               return -1;
           }
       }
       
       return mightBeCelebrity;
    }
};
