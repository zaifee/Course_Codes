#include <iostream>
#include<vector>
// Time Complexity will be O(n2)
using namespace std;
void selectionSort(vector<int>arr){
  int n = arr.size();
  for(int i=0; i<n-1; i++){
    int midIndex = i;
    for(int j=i+1; j<n; j++){
      if(arr[j] < arr[midIndex]){
        midIndex = j;
      }
    }
    //if min elment is find swapping with largest element
    swap(arr[i], arr[midIndex]);
  }
  //printing the array
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  vector<int>arr{30,10,5, 7,6};
  selectionSort(arr);



  return 0;
}
