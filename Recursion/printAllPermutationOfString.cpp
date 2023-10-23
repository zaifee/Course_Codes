/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void permutationOfString(string &s, int i){
    
    //base case 
    if(i >= s.length()){
        cout << s << " ";
        return;
    }
    
    //i ki har position par j ko rakh kar dekhna hai -- so we want loop 
    for(int j=i; j<s.length(); j++){ //j <= s.length() galti ki thi 
        
        swap(s[j], s[i]);
        
        permutationOfString(s, i+1);
        
        
        //backtracking -- doing bcz of we passed the string by reference 
        swap(s[j], s[i]);
    }
    
    
}



int main()
{
    string s = "abc";
    int i = 0;
    permutationOfString(s, i); 
    

    return 0;
}
