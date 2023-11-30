#include <iostream>
#include <queue>
using namespace std;

int main() {
  
queue<int>q;
q.push(10);
// q.pop();
q.push(20);
q.push(30);
q.push(40);
cout << "Last Element is " << q.back() << endl;
while(!q.empty()){
  cout << q.front() << " " << endl;;
  cout << " Queue Size " << q.size() << " ";
  q.pop();
}
cout  << endl;
if(q.empty()){
  cout << "Queue is empty " << endl;
}else{
  cout << "Not empty " << endl;
}



  return 0;
}
