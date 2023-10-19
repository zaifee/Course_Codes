
#include <iostream>

using namespace std;

bool checkSorted(int *arr, int size, int index){
    
    //base case 
    if(index >= size) return true;
    
    //processing 
    if(arr[index] < arr[index+1]){
        //recursive call 
   int aageKaAns =  checkSorted(arr, size, index+1);
       
       return aageKaAns;
    }
    
    
    
    return false;
    
    
}



int main()
{
   int arr[] = {10,30,20,20,60,70,5};
   int index = 0;
   int size = sizeof(arr)/sizeof(int);
  bool ans = checkSorted(arr, size, index);
  if(ans){
      cout << "Elements are Sorted " << endl;
  }
  else{
      cout << "Elements are not Sorted " << endl;
  }
  
   
   
   
    return 0;
}
