//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int>ans;
	   priority_queue<int, vector<int>, greater<int> >pq;
	   
	   for(int i=0; i<k; i++){
	       int element = arr[i];
	       
	       pq.push(element);
	   }
	   
	   //Processing other elements only if they are greater 
	   
	   for(int i=k; i<n; i++){
	       
	       
	       if(arr[i] > pq.top()){
	           pq.pop();
	           pq.push(arr[i]);
	       }
	   }
	   
	   while(!pq.empty()){
	       ans.push_back(pq.top());
	       pq.pop();
	   }
	   reverse(ans.begin(), ans.end());
	   
	   return ans;
	   
	}

};
