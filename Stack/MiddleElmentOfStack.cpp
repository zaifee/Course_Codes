#include <iostream>
#include<stack>
using namespace std;
// Deleting the Middle Element of stack 

void solve(stack<int>&st, int &pos, int &ans){

//base case 
if(pos == 1){
  // ans = st.top() //is line middle element ans me save ho jai ga 
  cout << " Deleting " << st.top() << endl;
  st.pop();
   return;
}
//1 case hmm solve karlenge
pos--;
int temp = st.top();
//ab pop kardo 
st.pop();

//recursion call 
solve(st, pos, ans);

//backtrack 
st.push(temp);



}



// finding the middle element of the stack 
int getMiddleElement(stack<int>&st){
  int size = st.size();
    if(st.empty()){
      cout << "Stack is empty no middle element !! "<<  endl;
      return -1;
    }else{
      //size check karlo even hai ya odd phir recursion call kardenge uske according 
       int pos = 0;
       if(size & 1){
        //odd element 
          pos = size/2+1;
       }else{
         pos = size/2;
       }

       int ans = -1; 
       solve(st, pos, ans);
       return ans;

    }

}


int main() {
  stack<int>st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  st.push(60);
  st.push(70);

int mid = getMiddleElement(st);


  return 0;
}
