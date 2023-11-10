#include <iostream>
#include<stack>
using namespace std;



void reverseOfStack(stack<int>&st){
//base case
if(st.empty()){
  return;
}

//1 case solve karo
int temp = st.top();
st.pop();

reverseOfStack(st);

//backtrack
insertAtBottom(st, temp);

}

int main(){
 stack<int>st;
  st.push(10);
  st.push(20);
  st.push(40);
  st.push(60);
  

  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
}
