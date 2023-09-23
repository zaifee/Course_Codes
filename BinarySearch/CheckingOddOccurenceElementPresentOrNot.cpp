#include <iostream>
#include <vector>
using namespace std;
int findOddOccuringElement(vector<int>arr){
  int s = 0;
  int n = arr.size();
  int e = n-1;
  while(s <= e){
    int mid = s + (e-s)/2;
    //single element wala case
    if(s == e) return s;

    //even wale element par khade hai tu
    if(mid % 2 == 0){
       if(arr[mid] == arr[mid+1]){
        //mid+2 bcz while checking if cond the next element is mid+1 is already compared or checked
           s = mid + 2;  
       }else{
        // me to ya right par khada ho ya ans par khada ho e = mid-1 se ans lost ho jai ga
         e = mid;
       }
    }
    //odd wala case
    if(mid % 2 == 1){
      if(arr[mid] == arr[mid-1]){
         s = mid+1; //right me jao mid+1 bcz next element is not compared yet
      }else{
        e = mid-1;
      }
    }
   
  }
  return -1;
}
int main() {
  vector<int>arr{10,10, 20,20, 4, 4 ,3 ,3 ,2 ,2, 60};
  int ansIndex = findOddOccuringElement(arr);
  if(ansIndex == -1){
    cout << "Element Not found " << endl;
  }else{
    cout << "Element found : " << arr[ansIndex] << endl;
  }
  return 0;
}
