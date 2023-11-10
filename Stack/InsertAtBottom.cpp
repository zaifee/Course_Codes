#include <iostream>
#include<stack>
using namespace std;

//Insert at bottom of stack
void insertAtBottom(stack<int>& st, int &element){
if(st.empty()){
  st.push(element);
  return;
}
//1 case solve karlo 
int temp = st.top();
st.pop();

//recursive call 
insertAtBottom(st, element);

//backtrack
st.push(temp);

}
int main(){
stack<int>st;
  st.push(10);
  st.push(20);
  st.push(40);
  st.push(60);
  int element = 50;
  
return 0;
}
