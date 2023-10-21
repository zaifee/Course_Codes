
#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int s, int e){
    int mid  = s + (e-s)/2;
    
    int  lenLeft = s-mid+1;
    int lenRight = e-(mid+1);
    
    int *leftArray = new int[lenLeft];
    int *rightArray = new int[lenRight];
    
    
    //statring from s copying into left array 
    int k = s;
    for(int i=0; i<lenLeft; i++){
        leftArray[i] = arr[k];
        k++;
    }
    
    //copying value into right array from mid + 1;
    k = mid + 1;
    for(int i=0; i<lenRight; i++){
        rightArray[i]=arr[k];
        k++;
    }
    
    
    //actual array in which left array is sorted or right array is sorted 
    int leftIndex = 0;
    int rightIndex = 0;
    
    //yaha par galti hogi 
    int mainIndex = 0;
    
    
    while(leftIndex < lenLeft && rightIndex < lenRight){
        
        if(leftArray[leftIndex] < rightArray[rightIndex]){
            arr[mainIndex] = leftArray[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else{
            arr[mainIndex] = rightArray[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }
    
    // 2 more case if left Array exhaust right remains 
    while(rightArray < rightIndex){
         arr[mainIndex] = rightArray[rightIndex];
            mainIndex++;
            rightIndex++;
    }
    
    // if right array exhaus -- left remains 
    while(leftArray < leftIndex){
        arr[mainIndex] = leftArray[leftIndex];
        mainIndex++;
        leftIndex++;
    }
    
}


void mergeSort(int &arr[], int s, int e, int mid){
    
    //base case 
    if(s >= e) return;
    
    int mid = s + (e-s)/2;
    
    //left arrya 
    mergeSort(arr, s, mid);
    
    mergeSort(arr, mid+1, e);
    
    merge(arr, s, e);
    
}


int main()
{
   
   vector<int>arr{2,1,9,7,4,6};
   int s = 0, e = arr.size()-1;
   mergeSort(arr, s, e);
   
   for(int i=0; i<arr.size(); i++){
      cout << arr[i] << endl;
   }
   

    return 0;
}
