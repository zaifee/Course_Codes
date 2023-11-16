#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int>st;
vector<int>previousSmallerElement(vector<int>&arr){
  st.push(-1);
  vector<int>ans(arr.size());
  for(int i=0; i<arr.size(); i++){
       int curr = arr[i];

      while(!st.empty() && st.top() >= curr){
        st.pop();
      }

      ans[i] = st.top();

      st.push(curr);
  }
  return ans;
}
int main() {
 
 vector<int>arr{5,5,6,5};
 vector<int>res(arr.size());

 res = previousSmallerElement(arr);

 for(auto i: res){
  cout << i << " ";
 }

  return 0;
}
