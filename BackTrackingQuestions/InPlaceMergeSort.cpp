class Solution {
public:
void merge(vector<int>&arr, int s, int mid, int e){
    int total_len = e-s+1;
    int gap = (total_len / 2) + (total_len % 2);
    while(gap > 0){
        int i = s, j = s + gap;
        while(j <= e){  //j ko last tak compare kar rahe hai tab tak outofbound na ho jai 
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : (gap/2) + (gap % 2); //yaha 1 likhna tha to galti ki
     }
    
    
}

void mergeSort(vector<int>&arr, int s, int e){
    if(s >= e) return;
    
    int mid = (s + e) >> 1;
    
    //recursive calls 
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    
    //merge 
    merge(arr, s, mid, e);
    
}
    vector<int> sortArray(vector<int>& arr) {
         mergeSort(arr, 0, arr.size()-1);
        return arr;
    }
};
