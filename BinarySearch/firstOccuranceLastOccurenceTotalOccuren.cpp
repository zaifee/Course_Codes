#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& arr, int key){
  int n = arr.size();
  int s = 0;
  int l = n - 1;
  while(s <= l){
    int mid = s + (l-s)/2;

    if(arr[mid] == key){
      return mid;
    }
    else if(arr[mid] > key){
       l = mid - 1;
    }else{
      s = mid + 1;
    }

  }

  return -1;

}


int firstOccurance(vector<int>& arr, int target){
  int n = arr.size();
  int s = 0;
  int e = n - 1;
  int ans = -1;
  while(s <= e){
    int mid = s + (e - s)/2;
   

    if(arr[mid] == target){
      ans = mid;
      e = mid - 1;
    }
    else if(arr[mid] > target){
      e = mid - 1;
    }else{
      s = mid + 1;
    }

  }

  return ans;

}




int lastOccurance(vector<int>& arr, int target){
  int n = arr.size();
  int s = 0;
  int e = n - 1;
  int ans = -1;
  while(s <= e){
    int mid = s + (e - s)/2;
   

    if(arr[mid] == target){
      ans = mid;
      s = mid + 1;
    }
    else if(arr[mid] > target){
      e = mid - 1;
    }else{
      s = mid + 1;
    }

  }

  return ans;

}


int main() {
  vector<int> arr{10, 20, 30, 30, 30, 30, 40 , 50};
  int key = 30;
  // cout << "Your key is present at Index: " << binarySearch(arr, key);
  cout << "Your first Index is present at Index: " << firstOccurance(arr, key) << endl;
  cout << "Your last Index is present at Index: " << lastOccurance(arr, key) << endl;
  int first = firstOccurance(arr, key);
  int last = lastOccurance(arr, key);
  int totalOccrence = (last - first) + 1;
  cout << "Total Occrence of element is: " << totalOccrence << endl;
  return 0;
}
