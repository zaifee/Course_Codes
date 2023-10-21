

#include <iostream>

using namespace std;
void printPermutations(string &str, int index){
    
    //base case 
    if(index >= str.length()){
        cout << str << " ";
         return;
    }
   
    
    //1 case solve karlo 
    // for every character of index of i   j ki har position par try kar rahe hai 
    for(int j=index; j<str.length(); j++){
        //swap index ko j and index 
        swap(str[j], str[index]);
        
        //recursive call 
        printPermutations(str, index+1);
        
        //backtracking 
        swap(str[j],str[index]);
        
    }
    
    
}
int main()
{
    string s = "abc";
    int index = 0;
    printPermutations(s, index);

    return 0;
}
