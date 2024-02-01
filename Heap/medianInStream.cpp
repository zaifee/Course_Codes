#include <iostream>
#include <queue>
using namespace std;
void solveForMedian(double &median, priority_queue<int> &maxi, 
priority_queue<int, vector<int>, greater<int> > &mini , int element){

if(maxi.size() == mini.size()){
   if(element > median){
      mini.push(element);
      median = mini.top();
   }
   else{
      maxi.push(element);
      median = maxi.top();

   }
}
else if(maxi.size() == mini.size()+1){
  if(element > median){
    mini.push(element);
  }
  else{
     int maxTop = maxi.top();
     maxi.pop();
     mini.push(maxTop);
     maxi.push(element);
  }
  median = (mini.top() + maxi.top())/2.0;
}
else if(mini.size() == maxi.size()+1){
if(element > median){
    int minTop = mini.top();
     mini.pop();
     maxi.push(minTop);
     mini.push(element);
    
  }
  else{
     maxi.push(element);
  }
  median = (mini.top() + maxi.top())/2.0;
}

}



int main() {
  int arr[] = {12,10,8,4,2,3,15};
  int n = 7;
double median = 0;
priority_queue<int> maxi; //maxheap 

priority_queue<int, vector<int>, greater<int> > mini; //minHeap


 for(int i=0; i<n; i++){
  /*
  when 
 n = 12, Median = 12
 n = 12, 10 => Median = 11
 n = 12, 10, 8 => Median = x
n = 12, 10, 8 , 4  => Median = 9;
n = 12, 10, 8 , 4 , 2 => Median = 8
n = 12, 10, 8 , 4 , 2, 3 =>Median=6





  */
  int element = arr[i];
  solveForMedian(median, maxi, mini, element);
  cout << "Median Found " << median << endl;
 }

  return 0;
}
