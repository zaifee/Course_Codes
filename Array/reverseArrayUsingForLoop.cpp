
#include <iostream>
#include <vector>
using namespace std;
void findReverse(vector<int> arr){
    //using two pointers approach
    
    //initialization             condition   updation
    for(int s=0 , e = arr.size()-1; s<=e; s++, e--){
        int temp;
        //swap logic
        temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
   //printing the array 
   for(int i=0; i<arr.size(); i++){
       cout << arr[i] << " ";
   }
}
int main()
{
   vector<int> arr{10,20,30,40,50,60};
   findReverse(arr);
    return 0;
}
