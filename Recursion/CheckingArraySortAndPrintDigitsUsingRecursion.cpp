/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool checkingSortedUsingRecusrion(int *arr, int size, int index){
    //base case 
    if(index >= size) return true;
    
    //processing 
    if(arr[index] < arr[index+1]){
       //base case
       
        //recursive call 
    checkingSortedUsingRecusrion(arr, size, index+1);
    }
    
   
    
    return false;
}
//number to difit 
void printDigit(int num, int index, vector<int>&ans){
    if(num == 0) return; //if a number is zero 
    
    //processing 
    int digit = num %10;
    
    //recursive  call
    printDigit(num/10, index+1, ans);
    
    //proceesing 
    ans.push_back(digit);
    
}
int main()
{
   int arr[] = {10,20,30,20};
   int size = sizeof(arr)/sizeof(int);
   int index = 0;
   
//  bool ans =  checkingSortedUsingRecusrion(arr, size, index);
//  if(ans){
//      cout << "Array is Sorted " << endl;
//  }
//  else{
//      cout << "Array is not sorted " << endl;
//  }
 
 //2 recursive fn to call printDigit;
 vecttor<int>num{43215};
 vector<int>ans;
 printDigit(num, ans);
 for(int num: ans){
     cout << num << endl; 
 }
   

    return 0;
}
