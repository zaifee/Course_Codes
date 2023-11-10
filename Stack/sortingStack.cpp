#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int>&st, int &element){

//base case
if(st.empty() || element > st.top()){
  st.push(element);
  return;
}

//1 case solve karlo
int temp = st.top();
st.pop();

//recursive call 
insertSorted(st, element);

//backtrack step
st.push(temp);

}

void sortingStack(stack<int>& st){
  if(st.empty()){
     return;
  }
  //stack se temp kardo or pop kardo 
  int temp = st.top();
  st.pop();

 sortingStack(st);

 //backtrack
 insertSorted(st, temp);
}



int main() {


//sort stack
stack<int>sst;
sst.push(10);
sst.push(2);
sst.push(15);
sst.push(3);

sortingStack(sst);
while(! sst.empty()){
  cout << sst.top() << " ";
  sst.pop();
}



  return 0;
}



