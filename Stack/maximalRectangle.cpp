class Solution {
    stack<int> st;

vector<int> nextSmallerElement(vector<int>& arr) {
    st.push(-1);
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int current = arr[i];
        while (!st.empty() && st.top() !=-1 && arr[st.top()] >= current) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return ans;
}

vector<int>previousSmallerElement(vector<int>&arr){
  st.push(-1);
  vector<int>ans(arr.size());
  for(int i=0; i<arr.size(); i++){
       int curr = arr[i];

      while(!st.empty() && st.top() !=-1 && arr[st.top()]  >= curr){
        st.pop();
      }

      ans[i] = st.top();

      st.push(i); //i means index
  }
  return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmallerElement(heights);
        //make sure karne next -1 na ho note galti ki thi yaha 
        for(int i=0; i<next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }
        vector<int>prev = previousSmallerElement(heights);

        int maxArea = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int length = heights[i];
            int width = next[i]-prev[i]-1;

            int currArea = length * width;
            maxArea = max(maxArea, currArea);
        }
   
     return maxArea;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;  //declaration me galti ki thi
        int n = matrix.size();  //no.of rows
        int m = matrix[0].size(); //no of column

        //converting into character
        for(int i=0; i<n; i++){
            vector<int>t;
            for(int j=0; j<m; j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]); //giving first row 
        //adding or updating all the rows 
        for(int i=1; i<n; i++){
//let's update current row wih previous row
            for(int j=0; j<m; j++){
                if(v[i][j]){
                    v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i])); //yaha galti ki thi

        }
        return area;

    }
};
