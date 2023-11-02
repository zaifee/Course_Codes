class Solution {
public:
void merge(vector<int>&arr, vector<int>&temp, int s, int mid, int e){
  //ek array s to mid start ho rha hai 
  //dusra array mid+1 se end tak 

  int i = s, j = mid+1;
  //taking k var to copy in the temporray array 
   int k = s; //copying from start in the temporary array 

  while(i <= mid && j <= e){
      if(arr[i] <= arr[j]) //checking which array element is smaller '<= bhul gya tha '
          temp[k++]  =  arr[i++];
      
      else
          temp[k++] = arr[j++];
      
  }    

  //pushing the remaining element 
//   if left array element is pushed and right elements remained
 
  while(i <= mid)
      temp[k++] = arr[i++]; //yaha galti  ki thi i++ ki jagah j++ likha tha
  

   while(j <= e){
      temp[k++] = arr[j++]; 
    }


  //copy temporary array into original array 
  // we will start copying from start to end 
  while(s <= e){
    arr[s]= temp[s];
       s++;
  }  


}



void mergeSort(vector<int>&arr, vector<int>&temp, int s, int e){
    
    //base case 
    if(s >= e) return;
    
   int  mid = s+ (e-s)/2;
    
    //divide
    //left array call 
    mergeSort(arr,temp, s, mid);
    
    //divide
    // right array call
    mergeSort(arr,temp, mid+1, e);
    
    //conquer
    merge(arr,temp, s, mid, e);
    
}


    vector<int> sortArray(vector<int>& nums) {
        //Making a temporary Array 
        vector<int>temp(nums.size(), 0);
        int s = 0;
        int e = nums.size()-1;
        mergeSort(nums, temp, s, e);
        return nums;
    }
};
