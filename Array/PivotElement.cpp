#include <iostream>
#include <vector>
using namespace std;
 int pivotElementIndex(vector<int>& arr){
      int n = arr.size();
      int s = 0;
      int e = n-1;
      int ans = -1;
      while(s <= e){
        int mid = s + (e-s)/2;
        //edge case 1 single element
        if(s == e) return s;
        if(mid-1 >= 0 && arr[mid] < arr[mid-1]){  //size me galti
            return mid-1;
        }else if(mid+1 < n && arr[mid] > arr[mid+1]){
            return mid;
        }else if(arr[s] > mid){  //left wali line me search 
            e = mid - 1;
        }else {
            s = mid + 1;  //right wali line me search
        }
      }
      return ans;

  }
int main() {
  vector<int> arr;
  // arr.push_back(12);
  arr.push_back(14);
  
  // arr.push_back(2);
  // arr.push_back(4);
  // arr.push_back(6);
  // arr.push_back(8);
  // arr.push_back(10);


  int pivotIndex = pivotElementIndex(arr);
  cout << "PivotIndex " << pivotIndex << endl;
  return 0;
}
