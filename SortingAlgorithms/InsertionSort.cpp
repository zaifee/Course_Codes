#include <iostream>
#include <limits.h>
#include<vector>
using namespace std;
void insertionSort(vector<int>arr){

  int n = arr.size();
  for(int i=1; i<n; i++){ //0 ele already sorted
    int key  = arr[i]; //1 element 
    int j = i-1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;

  }
  //printing the array 
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void bubbleSort(vector<int>arr){
  int n = arr.size();
  for(int i=0; i<n-1; i++){  //n-1 comparison honge 
   for(int j=0; j<n-i-1; j++){ 
    if(arr[j] > arr[j+1]){
      swap(arr[j], arr[j+1]);
    }
   }

  }
   for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
void selectionSort(vector<int>arr){
  int n = arr.size();
  
  for(int i=0; i<n-1; i++){
   int minIndex = i;
    
    for(int j=i+1; j<n; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    //swapping ith index element with minIndex element 
    swap(arr[i], arr[minIndex]);
    
  }
  
   for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
 vector<int>arr{55, 33, 11, 22};
 insertionSort(arr);
 bubbleSort(arr);
 selectionSort(arr);
  return 0;
}
