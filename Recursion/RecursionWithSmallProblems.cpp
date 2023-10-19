#include <iostream>
#include<limits.h>
using namespace std;
void minUsingRecursion(int *arr, int size, int index, int &mini){
    if(index >= size) return;
    
    //processing 
    mini = min(mini, arr[index]);
    
    //recusrive call 
    minUsingRecursion(arr, size, index+1, mini);
}


void maxUsingRecursion(int *arr, int size, int index, int &maxi){
    if(index >= size) return;
    
    //processing 
    maxi = max(maxi, arr[index]);
    
    //recusrive call 
    minUsingRecursion(arr, size, index+1, maxi);
}

void doubleTheArray(int *arr, int size, int index){
    if(index >= size) return;
    
    //processing 
    arr[index] = 2 * arr[index];
    cout << arr[index] << " ";
    
    doubleTheArray(arr, size, index+1);
}

void printAllOccurenceOfTarget(int *arr, int size, int index, int target){
    
    //base case 
    if(index >= size) return; 
    
    //processin 
    if(arr[index] == target){
        cout << index << " ";
    }
    
    //recursive call 
    
    printAllOccurenceOfTarget(arr, size,  index+1, target);
}

void UsingVector(int arr, int size, int index, vector<int>v){
    if(index >= size) return;
    
    if(arr[index] %2 == 0){
        v.push_back(arr[index]);
    }
    
    UsingVector(arr, size, index+1, v);
}

int main()
{
    // int arr[] = {30, 40, 20, 90, 10, 3, 1};
    // int arr[] = {10,20,30,40,50};
    // int size = sizeof(arr)/sizeof(int);
    int index = 0;
    
    //min element ka fn call 
    // int mini = INT_MAX;
    // minUsingRecursion(arr, size, index, mini);
    // cout << "Min in Array is: " << mini << endl;
    
    //max element ka fn call 
    // int maxi = INT_MIN;
    // maxUsingRecursion(arr, size, index, maxi);
    // cout <<" Max Element in Array is: " << maxi << endl;
    
    
    //double the array 
    // doubleTheArray(arr, size, index);   
    
    
    
    //recusrive fn 
    int arr[] = {10,20,30,10,40,10};
    int target = 10;
    int size = sizeof(arr)/sizeof(int);
    printAllOccurenceOfTarget(arr, size, index, target);
    
    
    vector<int>arr{10,20,30,40,50};
    vector<int>ans = UsingVector(arr, size, index)
    
    
    

    return 0;
}
