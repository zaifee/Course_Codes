#include <iostream>
using namespace std;
void printArray(int arr[], int size, int index){
  if(index >= size) return ;

  cout << arr[index] << " ";
  printArray(arr, size , index+ 1);
}

bool searcharrya(int *arr, int size, int index , int target){
  if(index >= size) return false;
  if(arr[index] == target) return true;

  //recursive calls
  bool aagekaans = printArray(arr, size, index+1, target);
  return aagekaans;
}

int main() {
 int arr[] = {10,20,30,40};
 int size = 4;
 int index = 0;
 int target = 40;
 cout << "Your searching value " << searcharrya(arr, size, index, target);
 printArray(arr, size, index);

  return 0;
}
