#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseQueue(queue<int>&q){
   stack<int>st;
  //queue se element lo, or stack me dalo 
while(!q.empty()){
  int frontElement = q.front();
  q.pop();
  st.push(frontElement);
}

//one by one stack se nikalo, or queue me daldo 
while(!st.empty()){
  int frontElem = st.top();
  st.pop();
  q.push(frontElem);
}

return;
}



void reverseUsingRec(queue<int>&q){

if(q.empty()){  //yaha galti ki !q.empty likh diya tha
  return;
}
int temp = q.front();
q.pop();

reverseQueue(q);

q.push(temp);
}








int main() {
  queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  // reverseQueue(q);
  reverseUsingRec(q);
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
