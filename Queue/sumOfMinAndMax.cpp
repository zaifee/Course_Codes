#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumOfMinAndMax(vector<int>&nums, int k){
  deque<int>dq,dq2;
  int ans = 0;  //yaha galti ki ans ko vector me declare kara tha aur use phir += kar raha tha

  for(int i=0; i<k; i++){
     
     //removing smaller element
     while(!dq.empty() && nums[i] >= nums[dq.back()]){  //back element se compare karna hai
         dq.pop_back();
     }

     //removing greater elment
     while(!dq2.empty() && nums[i] <= nums[dq2.back()]){  //back element se compare karna hai
         dq2.pop_back();
     }
      // inserting index, so that we can checkout other window
       dq.push_back(i);
       dq2.push_back(i);
  }

    //dq.front contains the min element
    //dq2.front contains the max element
     ans += nums[dq.front()] + nums[dq2.front()];

     
  for(int i=k; i<nums.size(); i++){
//out of window size ko remove kar diya 
if(!dq.empty() && i-dq.front() >= k){
   dq.pop_front();
}
if(!dq2.empty() && i-dq2.front() >= k){ //yaha galti ki thi
   dq2.pop_front();
}

//removing choote element 
  while(!dq.empty() && nums[i] >= nums[dq.back()]){
         dq.pop_back();
     }

    while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
        dq2.pop_back();
     }

     //addition 
     dq.push_back(i);
     dq2.push_back(i);


     //current window ka ans store karna hai 
     ans += nums[dq.front()] + nums[dq2.front()];

   


  }
    return ans;




}

int main() {
  vector<int>nums{2,5,-1,7,-3,-1,-2};
  int k = 4;
  cout <<  sumOfMinAndMax(nums, k);
  // cout << "Your answer is : " << ans << endl;
  return 0;
}

