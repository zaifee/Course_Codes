
#include <iostream>

using namespace std;
int BS(int *arr, int s, int e, int target){
    
    if(s > e) return -1;
    
    //processing 
    int mid = s + (e-s)/2;
    if(arr[mid] == target ){
        return mid;
    }
    else if(arr[mid] < target){
        //right me jao
        return BS(arr, mid+1, e, target);
    }
    else{
        return BS(arr, s, mid-1, target);
    }
    
    
    
}
int main()
{
    int arr[] = {10,30,20,50,70,60};

    int size = sizeof(arr)/sizeof(int);
    int s = 0, e = size;
    int target = 90;
    int foundIndex =  BS(arr, s, e, target);
  if(foundIndex != -1){
      cout << "your target is found at Index " << foundIndex << endl;
  }
  else{
      cout << "OOps! Your target is not exist in the Array "  << endl;
  }

    return 0;
}
