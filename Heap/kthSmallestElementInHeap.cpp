//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        
        priority_queue<int>pq;
        int n = r-l+1;
       
        //pushing smallest elment int the queue
        for(int i=0; i<k; i++){
            int element = arr[i];
            
            pq.push(element);
        }
        
        // remaining element tabhi process karoga jab wo root node se chote honge 
        for(int i=k; i<n; i++){
            int element = arr[i];
            
            if(element < pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        
        return pq.top();
        
        
        
        
    }
};
