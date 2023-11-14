#include <iostream>
#include <stack>
using namespace std;
bool checkRedundantBracket(string &s){
 stack<char>st;
  for(int i=0; i<s.length(); i++){
   
    char ch = s[i];

    if(ch == '(' || ch == '+' || ch == '-' ||ch == '*' || ch == '/'){
         st.push(ch);
    }
    else if(ch == ')'){
      //closing bracket ke sath operator milege 
      int operatorCount = 0;

     while(!st.empty() && st.top() != '('){  //lyaha galti ki thi != ki jagah == laga rha tha
     char temp = st.top();  //temp likhna bhul gaya tha
       if(temp == '+' || temp == '-' || temp == '*' || temp== '/' ){
             operatorCount++; //yaha increment karna bhul gaya 
       }
         
       st.pop();
     }
     //isse bhar aaye ho to open bracket mil gaya hoga 
      st.pop();

      if(operatorCount == 0){
        return true;
      }
    }
  }
  return false;
}



int main() {
  
  string s = "((a+b)))";

  bool ans = checkRedundantBracket(s);

  if(ans == true){
     cout << "Redundant Bracket is present " << endl;
  }
  else{
    cout << "Redundant Bracker is not present " << endl;
  }


  return 0;
}
