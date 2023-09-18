vector<int> superiorElements(vector<int>&arr) {
//     vector<int> ans;
//     int n = a.size();
// //brute force
 
//   for(int i=0; i<n; i++){
//     bool leader = true;

//      for(int j=i+1; j<n; j++){
//          if(a[j] > a[i]){
//              leader = false;
//              break;
//          }
     
//   }
//      if(leader == true){
//       ans.push_back(a[i]);
// }
//      return ans;
//   }

 vector<int> ans;
 int n = arr.size();
 int maxi = INT_MIN;
  //optimal approach
  for(int i=n-1; i>=0; i--){
      //checking last right element greater than left element
      if(arr[i] > maxi){
          ans.push_back(arr[i]);
      }
    //   update of current max element
    maxi = max(arr[i], maxi);
  }
//   O(n log n)

  sort(ans.begin(), ans.end());
  
  
  
  return ans;
 
    
    
}
