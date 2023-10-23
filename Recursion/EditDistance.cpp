class Solution {
public:
   int solve(string &str1, string &str2, int i, int j){
    // Base case 
    if(i >= str1.length()){
        // /word1 ki length khatam ho chuki hai
        // word2 ki length copy karni hai 

        return str2.length()-j;
    }

 // Base case 
    if(j >= str2.length()){
        // /word1 ki length khatam ho chuki hai
        // word2 ki length copy karni hai 

        return str1.length()-i; //yaha galti ki thi
    }

    // match karegi ya nhi karegi  

  int ans = 0;
    //match kargyi to skip 
    if(str1[i] == str2[j]){
       ans = 0 + solve(str1, str2, i+1, j+1); //yaha 0 add nhi kiya tha
    }
    else{  //string did not match 
     
     //insert 
     int opt1 = 1+solve(str1, str2, i, j+1); //yaha 1 add nhi kiya tha galti

     int opt2 = 1+solve(str1, str2, i+1, j);

     int opt3 = 1+solve(str1, str2, i+1, j+1);

     ans = min(opt1, min(opt2, opt3));


    }
    return ans;






   }
    int minDistance(string word1, string word2) {
        int i=0;
        int j = 0;

        int ans = solve(word1, word2, i, j);
        return ans;
    }
};
