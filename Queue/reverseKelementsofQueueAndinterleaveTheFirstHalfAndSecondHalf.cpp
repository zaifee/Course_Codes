#include <iostream>
#include <stack>
#include <queue>
using namespace std;



void reverseKElementsUsingQueue(queue<int>&q, int k){

  stack<int>st;
  int n = q.size(); 

//agar k number of elemets jitne queue unse zyada hai to nhi paiga 

   if(k > n || k == 0){
     cout << "The size of k is very large " << endl;
       return;
   }


  //push k elements into the queue
  for(int i=0; i<k; ++i){
    int element = q.front();
    q.pop();

   st.push(element);
  }


  //pop k elements from the stacks and push into the queue 
  while(!st.empty()){
    int top = st.top();
    st.pop();
    q.push(top);
  }


  // pop and push (n-k) elements fromt the queue 
  for(int i=0; i<(n-k); ++i){
    int temp = q.front();
    q.pop();
    q.push(temp);
  }

}

void interlearveQueue(queue<int>& first){
  queue<int>second;
  //odd wale case me size/2 tak chlea 
  //push first half of first queue in second queue
  int size = first.size();
  for(int i=0; i<size/2; i++){
      int temp = first.front();
      first.pop();

      second.push(temp);
  }


  //Merge both the halves 
  //into the original queue - named as first 
  for(int i=0; i<size/2; i++){
    int temp = second.front();
    second.pop();

    first.push(temp);

    //popping from the second queue 
     temp = first.front();
     first.pop();
     first.push(temp);
  }
}


int main() {
  queue<int>q;
  int k = 7;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);


 
//  reverseKElementsUsingQueue(q, k);
interlearveQueue(q);
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
