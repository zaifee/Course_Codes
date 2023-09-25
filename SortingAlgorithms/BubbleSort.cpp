#include <iostream>
#include <vector>
//Time Complexity for this program will be O(n2) 
using namespace std;
void bubbleSort(vector<int> v){
  int n = v.size();
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
      //compare if element at index j is greater than swapping with j+1 bcz it is the smaller element
      if(v[j] > v[j+1]){
        swap(v[j], v[j+1]);
      }
    }
  }
  //printing the array
  for(int i=0; i<n; i++){
    cout << v[i] << " ";
  }cout << endl;
}

int main() {
  vector<int>v{70,60,50,40,30};
  bubbleSort(v);


  return 0;
}
