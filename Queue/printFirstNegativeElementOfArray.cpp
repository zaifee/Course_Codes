#include <iostream>
#include <queue>
using namespace std;


void printFirstNegative(int *arr, int n, int k){

  queue<int>q;

  //process first k elements 
  for(int index=0; index<k; index++){
      int element = arr[index];
      if(element < 0){
        q.push(index); //index push karna hai;
      }
  }


//Process remaining window -> Removal and Addition 
for(int index = k; index < n; index++){
  //aage badhne se pehle purani wali ka ans nikal do
  //  cout << dq.front() << " "; 
  
   //last wali window ka answer nhi de pao ge isliye ushe alag se print kar rahe hai 
   if(q.empty()){
    cout << "0" << " "; 
    
   }else{
    cout << arr[q.front()] << " ";
   }

  //remvoal check - jo bhi index out of range ho, usko queue me se remove kardo 
   if(index - q.front() >= k){
    q.pop();   //ye kam while se bhi kar sakte the but har ek hi int ka removal ho rha hai tu 
     // we prefer to if
   }


   //addition check 
   if(arr[index] < 0){
     q.push(index);
   }


   //last wali window ka answer nhi de pao ge isliye ushe alag se print kar rahe hai 
   if(q.empty()){
    cout << "0" << " "; 
    
   }else{
    cout << arr[q.front()] << " ";
   }
}
}





int main() {
   
  // queue<int>q;
  // q.push(2);
  // q.push(-5);
  // q.push(4);
  // q.push(-1);
  // q.push(-2);
  // q.push(0);
  // q.push(5);

  int arr[] = {2,-5,4,-1,-2,0,5};
  // int size = sizeof(arr)/sizeof(int); 
  int size = 7;
  int k = 3;
  printFirstNegative(arr, size, k);




  return 0;
}
