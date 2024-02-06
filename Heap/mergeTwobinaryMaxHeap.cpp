// User function Template for C++

class Solution{
    public:
    void heapify(vector<int>&c, int i, int n){
        
        while(1){
            int leftChild = 2*i+1;
            int rightChild = 2*i+2; //0-based Indexing hai 
            
            int largestIndex = i;
            
            if(leftChild < n && c[leftChild] > c[largestIndex]){
                largestIndex = leftChild;
            }
            
            if(rightChild < n && c[rightChild] > c[largestIndex]){
                largestIndex = rightChild;
            }
            
            if(i == largestIndex){
                break;
            }
            else{
                swap(c[i], c[largestIndex]);
                i = largestIndex;
                // heapify(c, i, n);
            }
            
        }
        
        
        
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int>c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        
        for(int i=(c.size()/2)-1; i >= 0; i--){
            heapify(c, i, c.size());
        }
        
        return c;
    }
};
