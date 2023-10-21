
//Print all subarrays 
#include <iostream>
#include <vector>
using namespace std;
void subArrays_Util(vector<int>&nums, int s, int e){
    //base case 
    if(e == nums.size()) return;
    
    //processing s se end tak sab print karo 
    for(int i=s; i<=e; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    subArrays_Util(nums, s, e+1);
    
}

void printSubArray(vector<int>&nums){
    
    for(int s = 0; s<nums.size(); s++){
       int e = s;
        subArrays_Util(nums, s, e);
    }
}



int main()
{
    vector<int>arr{1,2,3,4,5};
   
//   subArrays_Util(arr, 0, 0); 
printSubArray(arr);
   
   

    return 0;
}
