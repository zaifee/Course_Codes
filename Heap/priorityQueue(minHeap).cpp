#include <iostream>
#include <queue>
using namespace std;

int main() {
  //Min Heap creation 
  priority_queue<int, vector<int>, greater<int> >pq;

  //insertion 
  pq.push(10);
  pq.push(20);
  pq.push(5);

  cout << "Top element of heap " << pq.top() << endl;
  return 0;
}
