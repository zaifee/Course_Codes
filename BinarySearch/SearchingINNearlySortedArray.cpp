#include <iostream>
#include <vector>
using namespace std;
int nearlySortedArray(vector<int> arr, int target){
  int n = arr.size();
  int s = 0;
  int e = n-1;
  while(s <= e){
    int mid = s + (e-s)/2;

    if(mid-1 >= 0 && arr[mid-1] == target){
      return mid-1;
    }
    if(arr[mid] == target){
      return mid;
    }
    if(mid+1< n && arr[mid+1] == target){
      return mid+1;
    }
    else if(target > arr[mid]){
      s = mid + 2; //bcz in this array 1 is compared two times if we don't use this cond
    }else{
      e = mid - 2;
    }
    mid = s + (e-s)/2;
  }
  return -1;
}


int main() {
  vector<int>arr{20,10,30,50,40,70,60};
  int target = 70;
  int n = arr.size();
  int targetIndex = nearlySortedArray(arr, target);
  if(targetIndex == -1){
    cout <<  "Element Not Exist "  << endl;
  }else{
    cout <<"Element is found " << targetIndex <<  endl;
  }



  return 0;
}
