int findMissingElement(vector<int>& arr){
  int n = arr.size();
  int s = 0;
  int l = n - 1;
 
  int ans = -1;
  while(s <= l){
    int mid = s + (l - s) / 2;
    // right me aajao
    int diff = arr[mid] - mid;
    if(diff == 1){
      // ignore diff shi hai right me jao 
      s = mid + 1;
    }
    else{
      // store ans and go to the left post 
      ans = mid;
      l = mid - 1;
    }

    }
    return ans+1;
  }
