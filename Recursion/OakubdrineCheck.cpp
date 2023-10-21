#include <iostream>

using namespace std;
bool palindromeCheck(string &str, int s, int e){
    //base case 
    if(s >= e){
        return true;
    }
    //Processing 
    if(str[s] != str[e]){
        return false;
    }
    //recursive call 
  return  palindromeCheck(str, s+1, e-1);
    
    
}
int main()
{
   string str = "racecar";
   int s = 0, e = str.size()-1;
 cout <<  palindromeCheck(str, s, e);
 
    return 0;
}
