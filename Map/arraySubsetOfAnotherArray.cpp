

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>mpp;
    string ans = "Yes";
    for(int i=0; i<n; i++){
        mpp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++){
        if(mpp.find(a2[i]) == mpp.end()){
              ans = "No";
              break;
              
        }
        else{
            
            if(mpp[a2[i]] > 0){
                mpp[a2[i]]--;
            }
            else{
                ans = "No";
                break;
            }
        }
        
    }
    return ans;
    
    
}
