void buildTree(int &i, int min, int max, vector<int>&A){
    if(i >= A.size()) return;
    
    if(A[i] > min && A[i] < max){
        int rootData = A[i++];
        buildTree(i, min, rootData, A);
        buildTree(i, rootData, max, A);
    }
}


int Solution::solve(vector<int> &A) {
    int min = INT_MIN, max = INT_MAX;
    int i=0;
    buildTree(i, min, max, A);
    return i == A.size();
}
