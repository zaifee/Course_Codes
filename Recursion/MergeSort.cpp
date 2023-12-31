class Solution {
public:

void merge(vector<int>&arr, int s, int e){
   int  mid  = s + (e-s)/2;
    
    int  lenLeft = mid-s+1;
    int lenRight = e-mid;
    
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
    int mainIndex = s;
    
    
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
    while(rightIndex < lenRight){ //yaha rightIndex ki while loop me galti ki thi
         arr[mainIndex] = rightArray[rightIndex];
            mainIndex++;
            rightIndex++;
    }
    
    // if right array exhaus -- left remains 
    while(leftIndex < lenLeft){  //yaha while  ki condition me galti ki thi
        arr[mainIndex] = leftArray[leftIndex];
        mainIndex++;
        leftIndex++;
    }
    
    //okay yaha galti ki  thi ye delete karna bhul gya ;
    delete [] leftArray;
    delete [] rightArray;
    
}


void mergeSort(vector<int>&arr, int s, int e){
    
    //base case 
    if(s >= e) return;
    
   int  mid = s + (e-s)/2;
    
    //left arrya 
    mergeSort(arr, s, mid);
    
    mergeSort(arr, mid+1, e);
    
    merge(arr, s, e);
    
}


    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        mergeSort(nums, s, e);
        return nums;
    }
};
