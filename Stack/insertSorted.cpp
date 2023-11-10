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

int main(){

  
stack<int>st;
  st.push(10);
  st.push(20);
  st.push(40);
  st.push(60);
   int element = 50;

   insertAtBottom(st, element);
  while(!st.empty()){
   cout << st.top << " ";
    st.pop();

  }
  return 0;
}
