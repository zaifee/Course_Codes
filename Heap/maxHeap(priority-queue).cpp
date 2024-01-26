#include <iostream>
#include <queue>
using namespace std;

int main() {
 
 priority_queue<int>pq; //it act as a max-heap

//insertion in heap
 pq.push(10);
 pq.push(20);
 pq.push(30);
 pq.push(40);
 pq.push(50);

//accessing in heap is possible via top element wise 
cout << "Top Element of heap is: " << pq.top() << endl;

//deleting value from heap 
pq.pop();
cout << "Top Element of heap is: " << pq.top() << endl;

cout << "Size of the heap is : " << pq.size() << endl;
if(pq.empty()){
  cout << "Queue Empty " << endl;
}
else{
  cout << "Queue not Empty " << endl;
}
 


  return 0;
}
