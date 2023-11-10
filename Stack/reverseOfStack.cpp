#include <iostream>
#include <stack>
using namespace std;
//Rerverse of a string using stack
int main() {
  stack<char>st;  //yaha galti ki char ki jagah int le liya tha

 string s= "Hellojee";
for(int i=0; i<s.size(); i++){
  //ek ek charater nikalo or stack me push karte raho 
  char ch = s[i];
  st.push(ch);
}

cout << endl;
//jab tak stack empty na ho jai data print karte raho or pop karte raho 
while(!st.empty()){
  cout << st.top()<<" ";
  st.pop();
}
cout << endl;




  return 0;
}
