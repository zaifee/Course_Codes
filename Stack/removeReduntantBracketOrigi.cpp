#include <iostream>
#include <stack>
using namespace std;
bool checkReduntant(string &s){
  stack<char>st;

  for(int i=0; i<s.length(); i++){
    char ch = s[i];

    if(ch == '(' || ch=='+' || ch=='-' || ch=='*' ||  ch=='/'){
       st.push(ch);
    }
    //clsoing bracket match kare or opertor count karte ja
    else if(ch == ')'){
      int opertorCount = 0;

      while(!st.empty() && st.top() != '('){
        char temp = st.top();

        if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
          opertorCount++;
        }
        st.pop();
      }

      //yaha par hmm jabhi pohuche ge jab opening bracket hoga;
      //hamare stack ke top par opening bracker hoga 
      st.pop();

      if(opertorCount == 0){
        return true;
      }
    }
  }
  //agar main yaha tak pohuha ho jab
  // aapke stack k top pr ek opening bracket hoga 
  // ek operator pakka mila hoga 
    return false;
}
int main() {
  
 string s = "((a+b) * (c+d))";

 bool ans = checkReduntant(s);

 if(ans == true){
  cout << "Reduntant bracket present" << endl;
 }
 else{
  cout << "Reduntant bracket is not present " << endl;
 }



  return 0;
}
